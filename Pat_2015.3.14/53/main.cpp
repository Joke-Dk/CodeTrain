#include <iostream>
#include <vector>

using namespace std;
vector<int> weights;
int N, M, S;
vector< vector<int> > maps(N);
vector< int> path;
vector< vector<int> > paths;
void travel(int id, int sum)
{
	
	sum+=weights[id];
	path.push_back(weights[id]);
	if( sum>S)
	{
		return;
	}
	if( sum==S && maps[id].size()==0)
	{
		paths.push_back(path);
	}
	else
	{
		for( int i=0; i<maps[id].size(); ++i)
		{
			travel( maps[id][i], sum);
			path.pop_back();
		}
	}

}
int main()
{
	freopen( "sample.in", "r", stdin);
	cin>>N>>M>>S;
	int i=0;
	weights.resize( N);
	maps.resize( N);
	for(i=0; i<N; ++i)
	{
		scanf("%d", &weights[i]);
	}
	for(i=0; i<M; ++i)
	{
		int index, nNode;
		cin>>index>>nNode;
		maps[index].resize( nNode);
		for( int j=0; j<nNode; ++j)
		{
			cin>>maps[index][j];
		}
	}
		
	travel( 0, 0);
	for( i=0; i<paths.size(); ++i)
	{
		for( int j=0; j<paths[i].size(); ++j)
		{
			if(j!=0)
			{ 
				cout<<" ";
			}
			cout<<paths[i][j];
		}
		cout<<endl;
	}
	return 0;
}
