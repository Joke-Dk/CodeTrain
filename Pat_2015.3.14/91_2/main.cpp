#include <iostream>
#include <vector>

using namespace std;
int M, N, L, T;
bool maps[1286][128][60];
bool visited[1286][128][60];
int maxDepth = 0;
void travel(int a, int b, int c)
{
	if( a<0 || a>M-1 || b<0 || b>N-1 || c<0 || c>L-1
		|| visited[a][b][c]	|| !maps[a][b][c] 	)
	{
		return;
	}
	maxDepth++;
	visited[a][b][c] = 1;
	travel( a-1, b, c);
	travel( a+1, b, c);
	travel( a, b-1, c);
	travel( a, b+1, c);
	travel( a, b, c-1);
	travel( a, b, c+1);
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
		for( int j=0; j<N; ++j)
		{
			for( int i=0; i<M; ++i)
			{
				maxDepth = 0;
				travel( i, j, k);
				if(maxDepth>=T)
				{
					sum+=maxDepth;
					cout<<maxDepth<<endl;
				}
			}
		}
	}
	cout<<sum<<endl;
	return 0;
	
}
