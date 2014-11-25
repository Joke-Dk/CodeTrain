#include <iostream>


using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)
int fav[210];
int stripe[10010];
int dp[210][10010];

int DP_func(int m, int n)
{
	if(m==0 || n==0)
		return 0;
	if(dp[m][n] != -1)
		return dp[m][n];
	if(stripe[m-1]==fav[n-1])
	{
		dp[m-1][n] = DP_func(m-1, n);
		dp[m][n] = dp[m-1][n]+1;
		return dp[m][n];
	}
	dp[m-1][n] = DP_func(m-1, n);
	dp[m][n-1] = DP_func(m, n-1);
	dp[m][n] = max(dp[m-1][n], dp[m][n-1]);
	return dp[m][n];

}
int main()
{
	//freopen("sample.in", "r", stdin);
	int N, M, L;
	cin>>N>>M;
	REP(i, M)
		cin>>fav[i];
	cin>>L;
	REP(i, L)
		cin>>stripe[i];
	REP(i, L+1)
		REP(j, M+1)
			dp[i][j] = -1;
	int ret = DP_func(L, M);

	cout<<ret<<endl;
	return 0;
}