#include <iostream>
#include <string>

using namespace std;

int main()
{
	freopen( "sample.in", "r", stdin);
	string str;
	cin>>str;
	char tag = str[0];
	
	int index = str.find( 'E');
	string digit = str.substr(1, index-1).erase( 1, 1);
	int exp = atoi(str.substr( index+1, str.length()-index-1).c_str());
	
	if( tag=='-')
	{
		cout<<"-";
	}
	if( exp<0)
	{
		cout<<"0.";
		for( int i=0; i<-1-exp; ++i)
		{
			cout<<"0";
		}
		cout<<digit;
	}
	else
	{
		if( exp+1<digit.length())
		{
			digit.insert( exp+1, ".");
		}
		else
		{
			int len = digit.length();
			for( int i=0; i<exp+1-len; ++i)
			{
				digit.insert( len, "0");
			}
		}
		cout<<digit;
	}

	cout<<endl;
	return 0;
}