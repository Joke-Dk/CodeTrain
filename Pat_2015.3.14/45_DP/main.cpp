#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
const int MAXN = 202;
const int MAXL = 10002;

int dp[MAXL][MAXN];
int fav[MAXN];
int seq[MAXL];
int N, M, L;

int max( int a, int b)
{
	return a>b?a:b;
}
int DP( int n, int l)
{
	if( n== -1|| l==-1)
	{
		return 0;
	}
	if( dp[n][l]!=-1)
	{
		return dp[n][l];
	}
	if( fav[n] == seq[l])
	{
		dp[n][l] = DP( n, l-1)+1;
	}
	else
	{
		dp[n][l] = max( DP(n-1, l), DP(n, l-1));
	}
	return dp[n][l];
}

int main()
{
	freopen( "sample.in", "r", stdin);
	memset( dp, -1, sizeof( dp));
	cin>>N;
	cin>>M;
	int i, j;
	for( i=0; i<M; ++i)
	{
		cin>>fav[i];
	}
	cin>>L;
	for( i=0; i<L; ++i)
	{
		cin>>seq[i];
	}
	cout<<DP( M-1, L-1)<<endl;
	return 0;
}

