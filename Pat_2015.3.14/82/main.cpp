#include <iostream>
#include <vector>
#include <string>

using namespace std;

string str1[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
string str3[3] = {"", "Wan", "Yi"};
string str2[4] = {"", "Shi", "Bai", "Qian"};
int c2d( char ch)
{
	return ch-'0';
}
vector<string> ret;
int main()
{
	freopen( "sample.in", "r", stdin);
	string digit;
	cin>>digit;
	if( digit[0]=='-')
	{
		ret.push_back("Fu");
		digit = digit.substr( 1, digit.length()-1);
	}
	
	if(digit==string("0"))
	{
		cout<<"ling"<<endl;
		return 0;
	}
	bool hasZero = 0;
	//
	for( int i=0; i<digit.length(); ++i)
	{
		int tmpD = c2d( digit[i]);
		if(tmpD!=0)
		{
			if(hasZero)
			{
				ret.push_back( str1[0]);
			}
			string tag1 = str1[tmpD];
			ret.push_back( tag1);
			hasZero = 0;	
		}
		else
		{
			hasZero = 1;
		}
		
		
		if((digit.length()-i-1)%4==0)
		{
			string tag3 = str3[ (digit.length()-i-1)/4];
			ret.push_back( tag3);
			hasZero = 0;
		}
		else if(tmpD!=0)
		{
			string tag2 = str2[ (digit.length()-i-1)%4];
			ret.push_back( tag2);
		}
	}
	
	for( int i=0; i<ret.size(); ++i)
	{
		if(ret[i]!=string(""))
		{
			if( i!=0){ cout<<" ";}
			cout<<ret[i];
		}
	}
	cout<<endl;
	return 0;
}