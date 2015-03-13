#include <iostream>
#include <string>
#include <vector>

using namespace std;

long int minD( long int a, long int b)
{
	if(a==0 || b==0)
		return 1;
	a = abs(a);
	b = abs(b);
	do
	{
		if(a<b)
		{
			int c=a;
			a=b; b=c;
		}
		a = a%b;
	}
	while( a!=0);
	return b;
}

class digit
{
public:
	long int a, b;
	long int tag;
	digit(){}
	digit( const digit & d)
	{
		a = d.a;
		b = d.b;
		tag = d.tag;
	}
	void getValue( int a0, int b0)
	{
		a=a0; b=b0;
		long int c = minD(a, b);
		a /= c; b /= c;
		tag = 1;
		if(a*b<0) tag=-1;
		a=abs(a); b=abs(b);
	}

	digit( string str)
	{
		int index = str.find( '/');
		a = atoi(str.substr( 0, index).c_str());
		b = atoi(str.substr( index+1, str.length()-1-index).c_str());
		getValue( a, b);
		//cout<<a<<" "<<b<<endl;
	}

	friend digit operator +(digit& d1, digit& d2)
	{
		digit ret;
		long int c = d1.tag*d1.a*d2.b + d2.tag*d2.a*d1.b;
		long int d = d1.b*d2.b;
		ret.getValue( c, d);
		return ret;
	}	

	friend digit operator -(digit& d1, digit& d2)
	{
		digit ret;
		long int c = d1.tag*d1.a*d2.b - d2.tag*d2.a*d1.b;
		long int d = d1.b*d2.b;
		ret.getValue( c, d);
		return ret;
	}	

	friend digit operator *(digit& d1, digit& d2)
	{
		digit ret;
		long int c = d1.tag*d1.a*d2.tag*d2.a;
		long int d = d1.b*d2.b;
		ret.getValue( c, d);
		return ret;
	}	

	friend digit operator /(digit& d1, digit& d2)
	{
		digit ret;
		long int c = d1.tag*d1.a*d2.tag*d2.b;
		long int d = d1.b*d2.a;
		ret.getValue( c, d);
		return ret;
	}	

	void output( )
	{
		//if 0
		if (b==0)
		{
			cout<<"Inf";
			return;
		}
		if(a==0)
		{
			cout<<"0";
			return;
		}
		
		
		long int a0=a, b0=b, c0=0;
		if( a>b)
		{
			c0 = a/b;
			a0 = a%b;
		}
		string beginStr = "", endStr = "";
		if( tag<0)
		{
			beginStr = "(-";
			endStr = ")";
		}
		cout<<beginStr;
		if(c0!=0)
		{
			cout<<c0;
		}
		if(a0!=0)
		{
			if(c0!=0)
			{
				cout<<" ";		
			}
			cout<<a0<<"/"<<b0;
		}
			
		cout<<endStr;
	}

};

int main()
{
	freopen( "sample.in", "r", stdin);

	string str1, str2;
	cin>>str1>>str2;
	digit d1(str1);
	digit d2(str2);
	// +
	digit ret=d1+d2;
	d1.output(); cout<<" + "; d2.output(); cout<<" = ";ret.output(); cout<<endl;
	
	// -
	ret=d1-d2;
	d1.output(); cout<<" - "; d2.output(); cout<<" = ";ret.output(); cout<<endl;

	// *
	ret=d1*d2;
	d1.output(); cout<<" * "; d2.output(); cout<<" = ";ret.output(); cout<<endl;

	// /
	ret=d1/d2;
	d1.output(); cout<<" / "; d2.output(); cout<<" = ";ret.output(); cout<<endl;

	return 0;
}
