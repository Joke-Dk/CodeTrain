#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int d1, d2;

int big( int d)
{
	char chs[10];
	sprintf( chs, "%04d", d);
	string str = chs;
	sort( str.begin(), str.end());
	d1 = atoi(str.c_str());
	reverse( str.begin(), str.end());
	d2 = atoi(str.c_str());

	if( d!=(d2-d1) )
	{
		printf( "%04d - %04d = %04d\n", d2, d1, d2-d1);
	}
	return d2-d1;
}

int main()
{
	freopen( "sample.in", "r", stdin);
	int digit;
	cin>>digit;
	if( digit==0)
	{
		printf( "%04d - %04d = %04d\n", digit, digit, digit);
		return 0;
	}
	int cur = digit;
	int pre = -1;
	while( pre!=cur)
	{
		pre = cur;
		cur = big( cur);
	}
	return 0;
}