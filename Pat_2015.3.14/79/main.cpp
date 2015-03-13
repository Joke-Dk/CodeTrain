#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

int N; ;
double P, R;
vector< vector<int>> maps;
vector< int> amounts;

double sum=0.0;
void travel(int id, int depth)
{
	if( maps[id].size()==0)
	{
		sum+=P*amounts[id]*pow(1.0+R/100.0, depth);
		return;
	}
	else
	{
		for( int i=0; i<maps[id].size(); ++i)
		{
			travel( maps[id][i], depth+1);
		}
	}
}

int main()
{
	freopen("sample.in", "r", stdin);
	cin>>N>>P>>R;
	maps = vector< vector<int>>(N);
	amounts = vector< int>( N, 0);
	for(int i=0; i<N; ++i)
	{
		int n;
		cin>>n;
		if( n!=0)
		{
			maps[i] = vector<int>(n);
			for( int j=0; j<n; ++j)
			{
				scanf( "%d", &maps[i][j]);
			}			
		}
		else
		{
			scanf( "%d", &amounts[i]);
		}
	}
	
	travel( 0, 0);
	//cout<<sum<<endl;
	printf("%.1f", sum);
	return 0;

}