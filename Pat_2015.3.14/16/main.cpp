#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
int prices[24];
bool earlyTime( string t1, string t2)
{
	for( int i=0; i<4; ++i)
	{
		int i1 = atoi(t1.substr( 3*i, 2).c_str());
		int i2 = atoi(t2.substr( 3*i, 2).c_str());
		if( i1>i2)
		{
			return 0;
		}
		else if(i2>i1)
		{
			return 1;
		}
	}
	return 0;
}

int units[3] = { 24*60, 60, 1};
//make sure t2>t1
int computeMinute( string t1, string t2)
{
	int minute1 = 0;
	int minute2 = 0;
	for( int i=0; i<3; ++i)
	{
		int i1 = atoi(t1.substr( 3+3*i, 2).c_str());
		int i2 = atoi(t2.substr( 3+3*i, 2).c_str());
		minute1 += i1*units[i];
		minute2 += i2*units[i];
	}
	return minute2 - minute1;
}

int units2[2] = { 24, 1};
int computePrice( string t1, string t2)
{
	int ret = 0;
	int hour1 = 0;
	int hour2 = 0;
	for( int i=0; i<2; ++i)
	{
		int i1 = atoi(t1.substr( 3+3*i, 2).c_str());
		int i2 = atoi(t2.substr( 3+3*i, 2).c_str());
		hour1 += i1*units2[i];
		hour2 += i2*units2[i];
	}
	//cout<<hour1<<" "<<hour2<<endl;
	for( int i=hour1+1; i<hour2; ++i)
	{
		ret += prices[i%24]*60;
	}
	int i1 = 60-atoi(t1.substr( 3+3*2, 2).c_str());
	int i2 = atoi(t2.substr( 3+3*2, 2).c_str());
	ret+=prices[hour1%24]*i1;
	ret+=prices[hour2%24]*i2;
	return ret;
}

class user
{
public:
	vector<string> _Times[2];
};



int JudgeTag( string tag)
{
	if( tag==string("on-line"))
	{
		return 0;
	}
	return 1;
}
int main()
{
	freopen( "sample.in", "r", stdin);
	for( int i=0; i<24; ++i)
	{
		cin>>prices[i];
	}
	int N;
	cin>>N;
	map< string, user> maps;
	for( int i=0; i<N; ++i)
	{
		string tmpId;
		cin>>tmpId;
		if(maps.find( tmpId)==maps.end())
		{
			maps[tmpId] = user();
		}
		string tmpTime, tmpTag;
		cin>>tmpTime>>tmpTag;
		maps[tmpId]._Times[ JudgeTag( tmpTag)].push_back( tmpTime);
	}
	
	//print
	for( map< string, user>::iterator it = maps.begin(); it!= maps.end(); ++it)
	{
		cout<<it->first<<endl;
		vector<string>* sortVec = it->second._Times;
		for( int i=0; i<2; ++i)
		{
			//vector<string> &sortVec = it->second._Times[i];
			sort(sortVec[i].begin(), sortVec[i].end(), earlyTime);
			for( int j=0; j<sortVec[i].size(); ++j)
			{
				cout<<i<<" "<<sortVec[i][j]<<endl;
			}
		}
		int i=0, j=0;
		while( i<sortVec[0].size() && j<sortVec[1].size())
		{
			if( !earlyTime(sortVec[0][i], sortVec[1][j]))
			{
				j++;
				continue;
			}
			if( earlyTime(sortVec[0][i], sortVec[1][j]) && i+1<sortVec[0].size() && earlyTime(sortVec[0][i+1], sortVec[1][j]))
			{
				i++;
				continue;
			}

			int retMinute = computeMinute( sortVec[0][i], sortVec[1][j]);
			float retPrice = (float)computePrice( sortVec[0][i], sortVec[1][j])/100.f;
			cout<<sortVec[0][i]<<" "<< sortVec[1][j]<<" "<<retMinute<<" "<<retPrice<<endl;
			i++;j++;
			
		}
	}
	
	return 0;
}

