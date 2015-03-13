#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int M, N, L, T;
bool maps[1286][128][60];
bool visited[1286][128][60];
int maxDepth = 0;

class int3
{
public:
	int a, b, c;
	int3( int a0, int b0, int c0)
	{
		a = a0;
		b = b0;
		c = c0;
	}
};
queue< int3> queues;

void add( int a, int b, int c)
{
	if( a<0 || a>M-1 || b<0 || b>N-1 || c<0 || c>L-1
		|| visited[a][b][c]	|| !maps[a][b][c] 	)
		{
			return;
		}
	queues.push( int3(a, b, c));
	visited[a][b][c] = 1;
}

void travel(int a0, int b0, int c0)
{
	queues = queue<int3>();
	add( a0, b0, c0);
	while( !queues.empty())
	{
		int3& head = queues.front();
		int a = head.a, b=head.b, c=head.c;
		queues.pop();
		maxDepth++;
		add( a-1, b, c);
		add( a+1, b, c);
		add( a, b-1, c);
		add( a, b+1, c);
		add( a, b, c-1);
		add( a, b, c+1);	
	}
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
				int tmpInt;
				scanf("%d", &tmpInt);
				maps[j][i][k] = tmpInt;
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
					//cout<<maxDepth<<endl;
				}
			}
		}
	}
	cout<<sum<<endl;
	return 0;
	
}
