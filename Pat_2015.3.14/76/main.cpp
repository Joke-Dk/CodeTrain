#include <iostream>
#include <queue>
#include <string.h>		//1 - contain memset
//#include <memory.h>	//2 - contain memset
using namespace std;
const int MAX = 1005;
bool maps[MAX][MAX];
int N, L;

queue< int> queues;
int depths[MAX];
bool visits[MAX];
int travel( int id)
{
	int sum=0;
	memset( visits, false, sizeof(visits));
	queues= queue<int>();
	depths[id] = 0;
	visits[id] = 1;
	queues.push( id);
	while( !queues.empty())
	{
		int cur = queues.front();
		if( depths[cur]>L)
		{
			break;
		}
		sum++;
		//cout<<" path: "<<cur<<" "<<depths[cur]<<endl;
		queues.pop();
		for( int i=0; i<N; ++i)
		{
			if( maps[cur][i] && !visits[i])
			{ 
				depths[i] = depths[cur]+1;
				visits[i] = 1;
				queues.push( i);
			}
		}
	}
	return sum;
}

int main()
{
	freopen( "sample.in", "r", stdin);
	cin>>N>>L;

	memset( maps, false, sizeof(maps));
	int i, j;
	for( i=0; i<N; i++)
	{
		int n;
		cin>>n;
		for( j=0; j<n; ++j)
		{
			int index;
			cin>>index;
			maps[index-1][i] = 1;
		}
	}

	int k;
	cin>>k;
	for( i=0; i<k; ++i)
	{
		int tmp;
		cin>>tmp;
		cout<<travel( tmp-1)-1<<endl;
	}
	return 0;

}