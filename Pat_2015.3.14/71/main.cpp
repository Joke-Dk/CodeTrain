#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

char lower( char ch)
{
	if( ch>='A' && ch<='Z')
	{
		return ch-'A'+'a';
	}
	return ch;
}

string lower( string str)
{
	for( int i=0; i<str.length(); ++i)
	{
		str[i] = lower(str[i]);
	}
	return str;
}
bool isAlphanumerical( char ch)
{
	ch = lower(ch);
	if( (ch>='a' && ch<='z') || (ch>='0' && ch<='9'))
	{
		return 1;
	}
	return 0;
}


int main()
{
	freopen( "sample.in", "r", stdin);
	string str;
	getline( cin, str);

	map< string, int> maps;
	int cur=0;
	while( cur<str.length())
	{
		if( !isAlphanumerical(str[cur]))
		{
			cur++;
			continue;
		}
		int size = 1;
		while( cur+size <str.length())
		{
			if( !isAlphanumerical( str[cur+size]))
			{
				break;
			}
			size++;
		}
		string word = lower(str.substr( cur, size));
		//insert
		if( maps.find( word)==maps.end())
		{
			maps[word] = 1;
		}
		else
		{
			maps[word]++;
		}

		cur+=word.length();
	}

	int maxCount = -1;
	string maxWord("");
	for( map< string, int>::iterator it = maps.begin(); it!=maps.end(); ++it)
	{
		if( maxCount<it->second)
		{
			maxCount=it->second;
			maxWord = it->first;
		}
	}
	cout<<maxWord<<" "<<maxCount<<endl;
	return 0;
}