#include <iostream>
#include <vector>
#include <string>

using namespace std;

long gcd( long a, long b)
{
	// a>b
	int tmp;
	if( a<b)
	{
		tmp =a;
		a=b; b=tmp;
	}
	if( b==0)return 1;
	while( tmp = a%b)
	{
		a=b;
		b=tmp;
	}
	return b;
}

class digit
{
public:
	long _tag, _a, _b;
	digit()
	{
		_tag = 1;
		_a = 0;
		_b = 1;
	}
	digit( string str)
	{
		int index = str.find('/');
		int a = atoi(str.substr( 0, index).c_str());
		int b = atoi(str.substr( index+1, str.length()-1-index).c_str());
		getValue( a, b);
	} 
	void getValue( long a, long b)
	{
		_tag = 1;
		if(a*b<0){ _tag =-1;}
		_a = abs(a); _b = abs(b);
		int _gcd = gcd( _a, _b);
		_a /= _gcd;
		_b /= _gcd;
	}
	
	friend digit operator +( const digit & d1, const digit & d2)
	{
		digit ret;
		int a = d1._tag*d1._a*d2._b+d2._tag*d2._a*d1._b;
		int b = d1._b*d2._b;
		ret.getValue( a, b);
		return ret;
	}
	
	void output()
	{
		if(_tag<0)
		{
			cout<<"-";
		}
		if( _b==0)
		{
			cout<<"Inf"<<endl;
			return;
		}
		if( _a==0)
		{
			cout<<"0"<<endl;
			return;
		}
		int c=_a/_b;
		int a=_a%_b;
		if( c!=0)
		{
			cout<<c;
		}
		if( a!=0)
		{
			if(c!=0)
			{cout<<" ";}
			printf("%d/%d", a, _b);
		}
		cout<<endl;
	}
};

int main()
{
	freopen( "sample.in", "r", stdin);
	int N;
	cin>>N;
	digit sum;
	for( int i=0; i<N; ++i)
	{
		string tmpStr;
		cin>>tmpStr;
		sum = sum + digit( tmpStr);
	}
	sum.output();
	return 0;
}