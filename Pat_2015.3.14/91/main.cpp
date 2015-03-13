#include <iostream>
#include <vector>

using namespace std;
int M, N, L, T;
bool maps[1286][128][60];
bool visited[1286][128][60];
int travel(int a, int b, int c)
{
	if(visited[a][b][c]|| !maps[a][b][c])
	{
		return 0;
	}
	visited[a][b][c] = 1;
	for(int i=max( a-1, 0); i<=min( a+1, M-1); ++i)
	{
		for(int j=max( b-1, 0); j<=min( b+1, N-1); ++j)
		{
			for(int k=max( c-1, 0); k<=min( c+1, L-1); ++k)
			{
				if( ((abs(a-i)+abs(b-j)+abs(c-k))==1) && !visited[i][j][k] && maps[i][j][k])
				{
					return travel( i, j, k)+1;
				}
			}
		}
	}
	return 1;
}
int main()
{
	freopen( "sample.in", "r", stdin);
	cin>>M>>N>>L>>T;
	for(int k=0; k<L; ++k)
	{
		for( int j=0; j<M; ++j)
		{
			for( int i=0; i<N; ++i)
			{
				cin>>maps[j][i][k];
				visited[j][i][k]=0;
			}
		}
	}
	
	int sum=0;
	for(int k=0; k<L; ++k)
	{
		for( int j=0; j<M; ++j)
		{
			for( int i=0; i<N; ++i)
			{
				int tmp = travel( j, i, k);
				if( tmp>=T)
				{
					sum+=tmp;
					cout<<tmp<<endl;
				}
			}
		}
	}
	cout<<sum<<endl;
	return 0;
	
}
