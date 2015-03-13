#include <iostream>
#include <string>
#include <vector>
using namespace std;

class digit
{
public:
	int tag;
	digit( int len)
	{
		tag = 1;
		_value = vector< int>( len, 0);
	}
	digit( string str)
	{
		int start = 0;
		int len = str.length();
		tag = 1;
		if( str[0]=='-')
		{
			start++;
			tag = -1;
			len--;
		}
		_value = vector< int>( len, 0);
		for( int i=start; i<len; ++i)
		{
			_value[i-start] = str[i]-'0';
		}
	}
	vector< int> _value;
	friend digit operator +( digit& a, digit& b)
	{
		int lenA = a._value.size();
		int lenB = b._value.size();
		int lenC = max( lenA, lenB )+1;
		digit ret( lenC);
		// add
		for( int i=0; i<lenC; ++i)
		{
			int valA=0, valB=0, nextC=0;
			if(i<lenA)
			{
				valA =  a._value[lenA-1-i]*a.tag;
			}
			if(i<lenB)
			{
				valB =  b._value[lenB-1-i]*b.tag;
			}
			
			nextC = 
		}
	}
};

int main()
{
	return 0;
}
