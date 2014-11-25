#include <cstdio>

#define min(a, b) ((a) <= (b) ? (a) : (b))
#define max(a, b) ((a) >= (b) ? (a) : (b))
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;

int N, M, L;
int fav[210];
int strip[10010];

int dp[210][10010];
int gao(int m, int n) {
    if(0 == m || 0 == n) {
        return 0;
    }

    if(dp[m][n] != -1) {
        return dp[m][n];
    }

    if(fav[m-1] == strip[n-1])
    {
        dp[m][n-1] = gao(m, n-1);
        dp[m][n] = dp[m][n-1] + 1;
        return dp[m][n];
    }
    else {
        dp[m-1][n] = gao(m-1, n);
        dp[m][n-1] = gao(m, n-1);
        dp[m][n] = max( dp[m-1][n], dp[m][n-1] );
        return dp[m][n];
    }
    return -1;
}

int main(void) {
    scanf("%d", &N);
    scanf("%d", &M);
    REP(i, M) {
        scanf("%d", &fav[i]);
    }
    scanf("%d", &L);
    REP(i, L)
        scanf("%d", &strip[i]);
    REP(i, M+1) REP(j, L+1) dp[i][j] = -1;
    printf("%d\n",gao(M, L));
    return 0;
}