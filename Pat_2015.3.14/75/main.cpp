#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int N, K, M;

int str2int( string str)
{
	return atoi( str.c_str());
}
vector<int> titles;

class user
{
public:
	int _id;
	vector<int> _scores;
	user(){};
	user( int id)
	{
		_id = id;
		_scores = vector<int>(K, -2);
	}

	int getScore() const
	{
		int sum = 0;
		for( int i=0; i<_scores.size(); ++i)
		{
			if( _scores[i]>0)
			{
				sum += _scores[i];
			}
		}
		return sum;
	}

	int getTitleNum() const
	{
		int count = 0;
		for( int i=0; i<_scores.size(); ++i)
		{
			if( _scores[i]==titles[i])
			{
				count++;
			}
		}
		return count;
	}

	bool isVaild()
	{
		for( int i=0; i<_scores.size(); ++i)
		{
			if( _scores[i]>=0)
			{
				return 1;
			}
		}
		return 0;
	}

	friend bool operator < (const user &u1, const user &u2 )
	{
		int s1 = u1.getScore();
		int s2 = u2.getScore();
		if( s1>s2)
		{
			return 1;
		}
		else if(s1==s2)
		{
			int c1 = u1.getTitleNum();
			int c2 = u2.getTitleNum();
			if( c1>c2)
			{
				return 1;
			}
			else if(c1==c2)
			{
				return u1._id < u2._id;
			}
		}
		return 0;
	}

	void output()
	{
		printf("%05d %d", _id, getScore());
		for( int i=0; i<K; ++i)
		{
			if( _scores[i]==-2)
			{
				printf( " -");
			}
			else if( _scores[i]==-1){ printf(" 0");}
			else
			{
				printf( " %d", _scores[i]);
			}
		}
		printf("\n");
	}

};
int main()
{
	freopen( "sample.in", "r", stdin);

	cin>>N>>K>>M;
	titles = vector<int>(K);
	int i, j;
	for( i=0; i<K; ++i)
	{
		cin>>titles[i];
	}
	map< int, user> maps;
	for( i=0; i<M; ++i)
	{
		int tmpID, tag, score; 
		cin>>tmpID>>tag>>score;
		if( maps.find( tmpID)==maps.end())
		{
			maps[tmpID] = user(tmpID);
		}
		if( score> maps[tmpID]._scores[tag-1])
		{
			maps[tmpID]._scores[tag-1] = score;
		}	
	}
	vector< user> sorted;
	for( map< int, user>::iterator it = maps.begin(); it!=maps.end(); ++it)
	{
		sorted.push_back( it->second);
	}
	sort( sorted.begin(), sorted.end());
	
	int preScore = -1000;
	int preRank = 0;
	int count = 0;
	for( i=0; i<sorted.size(); ++i)
	{
		if(sorted[i].isVaild())
		{
			count++;
			if( sorted[i].getScore()!=preScore)
			{
				preScore = sorted[i].getScore();
				cout<<count<<" ";
				preRank = count;
			}
			else
			{
				cout<<preRank<<" ";
			}

			
			sorted[i].output();
		}
	}
	return 0;
}