#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;


bool wordBreak( string s, set<string> &dict)
{
	vector<bool> tmpB;
	tmpB.resize( s.length()+1, 0);
	tmpB[0] = 1;
	for(int i=1; i<s.length()+1; ++i)
	{
		for( int j=0; j<i; ++j)
		{
			if( tmpB[j] && dict.find( s.substr(j, i-j))!=dict.end())
			{
				tmpB[i] = 1;
			}
		}
	}
	
	return tmpB[s.length()];
}

int main()
{
	//freopen( "sample.in", "r", stdin);

	string s = "leetcode";
	set<string> dict;
	dict.insert( "leet");
	dict.insert( "code");
	cout<<wordBreak( s, dict)<<endl;
	return 0;
}