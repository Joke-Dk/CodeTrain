#include <iostream>
#include <string>
const int MAX = 205;
const int INF = 10000;

using namespace std;

int N, K;
int [MAX][MAX] map;
int [MAX] dis;
bool [MAX] visited;

int main()
{
	cin>> N>> K;
	
	//init
	for( int i=0; i<N; ++i)
	{
		visited[i] = 0;
		dis[i] = INF;
		for( int j=0; j<N; ++j)
		{
			map[i][j] = INF;	
		}
	}
	
	for( int i=0; i<N; ++i)
	{
		for( )
	}
}