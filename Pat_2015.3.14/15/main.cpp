#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool judge( int digit)
{
	if(digit==1)
	{
		return 0;
	}
	for( int i=2; i<digit/2; ++i)
	{
		if(digit%i==0)
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	//freopen( "sample.in", "r", stdin);
	while(1)
	{
		int digit, radix;
		cin>>digit;
		if(digit<0){
			return 0;
		}
		cin>>radix;
		
		vector<int> arrs;
		int tmp = digit;
		while( tmp!=0)
		{
			arrs.push_back( tmp%radix);
			tmp /= radix;
		}
		int digitReverse = 0;
		for( int i=0; i<arrs.size(); ++i)
		{
			digitReverse *= radix;
			digitReverse += arrs[i];
		}
		
		bool flag = judge( digit)&& judge( digitReverse);
	
		
		if(flag)
		{
			cout<<"Yes"<<endl;
		}
		else
		{
			cout<<"No"<<endl;
		}
		
	}
	return 0;
}