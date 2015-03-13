#include <iostream>

#include <string>
#include <string.h>
#include <map>
#include <vector>
using namespace std;
const int MAX = 205;
const int INF = 0x7FFFFFFF;

int maps[MAX][MAX];
int len[MAX];
bool visit[MAX];
int happiness[MAX];
int N, K;
map< string, int> id;
map< int, string> rid;
void dij()
{
	int cur = 0;
	int i;
	len[cur] = 0;
	for( i=0; i<N; ++i)
	{
		visit[cur] = 1;
		int j;
		for( j=0; j<N; ++j)
		{
			if( !visit[j] && maps[cur][j]+len[cur] < len[j])
			{
				len[j] = maps[cur][j]+len[cur];
			}
		}

		int tmpLen = INF;
		for( j=0; j<N; ++j)
		{
			if( !visit[j] && len[j]<tmpLen)
			{
				cur = j;
				tmpLen = len[j];
			}
		}
	}
}

vector<int> paths;
vector<int> retPath;
int maxSum = -1;
int minDepth = INF;
int numpath = 0;
void travel( int cur, int dis, int depth, int sum)
{

	visit[cur] = 1;
	paths.push_back( cur);
	if(dis>len[id["ROM"]])
	{
		return;
	}
	if( dis == len[id["ROM"]] && cur == id["ROM"])
	{
		numpath++;
		//record
		if( maxSum<sum || (maxSum==sum && minDepth>depth))
		{
			maxSum = sum;
			minDepth = depth;
			retPath = paths;
		}
	

	}
	else
	{
		int i;
		for( i=0; i<N; ++i)
		{
			if( !visit[i] && maps[cur][i]<INF)
			{
				travel( i, dis+maps[cur][i], depth+1, sum+happiness[i]);
				visit[i] = 0; 
				paths.pop_back();
			}
		}
	}
}

int main()
{
	freopen( "sample.in", "r", stdin);
	string start;
	cin>>N>>K>>start;
	id[start] = 0;
	happiness[0] = 0;
	rid[0] = start;
	int i;
	memset( maps, INF, sizeof( maps));
	memset( len, INF, sizeof(len));
	memset( visit, false, sizeof(visit));
	for( i=1; i<N; ++i)
	{
		string str;
		int tmp;
		cin>>str>>tmp;
		id[str] = i;
		rid[i] = str;
		happiness[i] = tmp;
	}

	for( i =0 ;i<K; ++i)
	{
		string str1, str2;
		int dis;
		cin>>str1>>str2>>dis;
		maps[ id[str1]][ id[str2]] = dis;
		maps[ id[str2]][ id[str1]] = dis;
	}

	dij();

	memset( visit, false, sizeof(visit));
	travel( 0, 0, 0, 0);
	cout<<numpath<<" "<<len[id["ROM"]]<<" "<<maxSum<<" "<<maxSum/minDepth<<endl;
	for( i=0; i<retPath.size(); ++i)
	{
		if(i)
		{
			cout<<"->";
		}
		cout<<rid[retPath[i]];
	}
	cout<<endl;
	return 0;
}