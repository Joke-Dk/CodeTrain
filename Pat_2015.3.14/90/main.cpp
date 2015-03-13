#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class node
{
public:
	vector<int> _child;
};
	
vector<node> arrs;
vector<int> depth;
	
void travel( int index, int deep)
{
	depth[index] = deep;
	for( int i =0; i<arrs[index]._child.size(); ++i)
	{
		travel( arrs[index]._child[i], deep+1);
	}
}

int main()
{
	freopen("sample.in", "r", stdin);
	int N;
	double P, R;
	cin>>N>>P>>R;
	arrs = vector<node>(N);
	depth = vector<int>(N, -1);
	int root;
	for(int i=0; i<N; ++i)
	{
		int tmpRoot;
		cin>>tmpRoot;
		if( tmpRoot==-1)
		{
			root = i;
		}
		else
		{
			arrs[ tmpRoot]._child.push_back( i);
		}		
	}
	
	travel( root, 0);
	int maxDepth = 0;
	int maxCount = 0;
	for( int i=0; i<N; ++i)
	{	
		if( depth[i]>maxDepth)
		{
			maxDepth = depth[i];
			maxCount = 1;
		} 
		else if( depth[i]==maxDepth)
		{
			maxCount++;
		}
	}
	double HighPrice = P*(pow(1.f+R/100.f,double(maxDepth)));
	printf("%.2lf %d\n", HighPrice, maxCount);

	return 0;
}