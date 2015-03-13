#include <iostream>
#include <vector>
const int MAX = 505;
const int INF = 10000;
int map[MAX][MAX];
int bikes[MAX];
int dis[MAX];
bool visited[MAX];

using namespace std;
int Cmax, N, Sp, nRoad;

void dijk()
{
	int curId = 0;
	dis[ curId] = 0;
	for( int i=0; i<N; ++i)
	{
		visited[ curId] = 1;
		for( int j=0; j<N; ++j)
		{
			if( !visited[j] && dis[j]>dis[ curId]+map[curId][j])
			{
				dis[j] = dis[ curId]+map[curId][j];
			}
		}
		
		//find the min distance
		int minDis = INF;
		for( int j=0; j<N; ++j)
		{
			if( !visited[j] && dis[j]<minDis)
			{
				minDis = dis[j];
				curId = j;
			}
		}
	}
}

vector<int> curPath;
vector<int> minPath;
int minBikes = INF;
int minLeft = INF;

void compute( vector<int>& path)
{
	int need = 0;
	int left = 0;
	for( int i=1; i<path.size(); ++i)
	{
		if( bikes[path[i]]<Cmax/2)
		{
			if( bikes[path[i]]+left>=Cmax/2)
			{
				left -= Cmax/2-bikes[path[i]];
			}
			else
			{
				need += Cmax/2-bikes[path[i]]-left;
				left = 0;
			}
		}
		else
		{
			left += bikes[path[i]]-Cmax/2;
		}
	}
	if(need<minBikes || (need==minBikes && left<minLeft) )
	{
		minBikes = need;
		minPath = path;
		minLeft = left;
	}
}

void find( int _id, int curDis)
{
	if(curDis>dis[Sp])
	{
		return;
	}
	visited[_id] = 1;
	curPath.push_back( _id);
	if( _id == Sp && curDis == dis[Sp])
	{
		compute( curPath);
	}
	else
	{
		for( int i=0; i<N; ++i)
		{
			if( !visited[i] && map[ _id][i]!=INF)
			{
				find( i, curDis+map[ _id][i]);
			}
		}
	}
	visited[_id] = 0;
	curPath.pop_back();
}

int main()
{
	freopen( "sample.in",  "r",  stdin);
	cin>>Cmax>>N>>Sp>>nRoad;
	N++;
	bikes[0] = 0;
	for(int i=1; i<N; ++i)
	{
		cin>>bikes[i];
	}
	
	//init
	for( int i=0; i<N; ++i)
	{
		dis[i] = INF;
		visited[i] = 0;
		for( int j=0; j<N; ++j)
		{
			map[i][j] = INF;
		}
	}
	
	for( int i=0; i<nRoad; ++i)
	{
		int index0, index1;
		cin>>index0>>index1;
		cin>>map[index0][index1];
		map[index1][index0] = map[index0][index1];
	}
	dijk();	
	for( int i=0; i<N; ++i)
	{
		visited[i] = 0;
	}

	
	find( 0, 0);
	cout<<minBikes<<" 0";
	for( int i=1; i<minPath.size(); ++i)
	{
		cout<<"->"<<minPath[i];
	}
	cout<<" "<<minLeft<<endl;
	return 0;
}
