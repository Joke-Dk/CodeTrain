#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class student
{
public:
	int _ge, _gi;
	vector<int> choices;
	int _id;
	student( int id, int ge, int gi, vector<int>& ch0)
	{
		_id = id;
		_ge = ge;
		_gi = gi;
		choices = ch0;
		
	}
	friend bool operator <( const student & a, const student &b)
	{
		if(a._ge+a._gi>b._ge+b._gi)
		{
			return 1;
		}
		else if(a._ge+a._gi==b._ge+b._gi)
		{
			return a._ge > b._ge;
		}
		return 0;
	}
	
	friend bool operator ==( const student & a, const student &b)
	{
		if(a._ge+a._gi!=b._ge+b._gi)
		{
			return 0;
		}
		else if(a._ge != b._ge)
		{
			return 0;
		}
		return 1;
	}
};

bool cmp( student * a, student *b)
{
	return a->_id<b->_id;
}
int main()
{
	int N, M, K;
	freopen("sample.in", "r", stdin);
	cin>>N>>M>>K;
	vector< int> limits(M);
	vector< vector<student *>> schools(M);
	for(int i=0; i<M; ++i)
	{
		cin>>limits[i];
	}
	vector< student> students;
	for( int i=0; i<N; ++i)
	{
		int ge, gi, a, b, c;
		vector<int> tmp(K);
		cin>>ge>>gi;
		for( int j=0; j<K; ++j)
		{
			cin>>tmp[j];
		}
		students.push_back( student( i, ge, gi,tmp));
	}
	
	//sort
	vector< student> sorted = students;
	sort( sorted.begin(), sorted.end());
	for( int i=0; i<N; ++i)
	{
		for( int j=0; j<K; ++j)
		{
			int choice = sorted[i].choices[j];
			if( schools[choice].size()<limits[choice] ||
				*(schools[choice]).back() ==sorted[i])
				{
					schools[choice].push_back( &sorted[i]);
					break;
				}
		}
	}
	
	for(int i=0; i<M; ++i)
	{
		vector< student*> tmp;
		tmp = schools[i];
		sort( tmp.begin(), tmp.end(), cmp);
		for(int j=0; j<tmp.size(); ++j)
		{
			if( j!=0){ cout<<" ";}
			cout<<tmp[j]->_id;
		}
		cout<<endl;
	}
	return 0;
}