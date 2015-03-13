#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp( pair< char, int> a, pair< char, int> b)
{
	return a.second < b.second;
}

char a2A( char a)
{
	if( a<='z' && a>='a')
	{
		return a+'A'-'a';
	}
	return a;
}
int main()
{
	freopen( "sample.in",  "r",  stdin);
	map< char, int> maps;
	string str1, str2;
	cin>>str1>>str2;
	
	for( int i=0; i<str1.length(); ++i)
	{
		if( maps.find( a2A(str1[i]))==maps.end())
		{
			maps[a2A(str1[i])] = i;
		}
	}
	
	for( int i=0; i<str2.length(); ++i)
	{
		maps[a2A(str2[i])] = -1;
	}
	
	vector< pair<char, int>> detected;
	for( map<char, int>::iterator it=maps.begin(); it!=maps.end(); ++it)
	{
		if( it->second!=-1)
		{
			detected.push_back( make_pair( it->first, it->second));
		}
	}
	sort( detected.begin(), detected.end(), cmp);
	for( int i=0; i<detected.size(); ++i)
	{
		cout<<detected[i].first;//<<" "<<detected[i].second<<endl;
	}
	cout<<endl;
	return 0;
}