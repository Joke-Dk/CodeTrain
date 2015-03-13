#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
	freopen( "sample.in", "r", stdin);
	set< char> hm;
	string s1, s2;
	//cin>>s1;
	getline( cin, s1);
	getline( cin, s2);

	for(int i=0; i<s2.length(); ++i)
	{
		hm.insert( s2[i]);
	}
	
	for(int i=s1.length(); i>=0; --i)
	{
		if( hm.find( s1[i])!=hm.end())
		{
			s1.erase( s1.begin()+i);
		}
	}
	cout<<s1<<endl;
	return 0;
}