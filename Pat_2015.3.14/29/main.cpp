#include <iostream>
#include <vector>

using namespace std;

int main()
{	
	freopen( "sample.in", "r", stdin);
	long int N[2];
	vector<long int> arrs[2];
	for( int k=0; k<2; ++k)
	{
		cin>>N[k];
		arrs[k] = vector<long int>(N[k], 0);
		for( long int i=0; i<N[k]; ++i)
		{
			scanf( "%ld", &arrs[k][i]);
		}
	}
	
	//sort
	long int nMedian = (N[0] + N[1]+(long int)1)/(long int)2;
	
	int tag = 0;
	long int index[2] = {0, 0};
	long int count = 0;
	long int median = 0;
	while( index[0]<N[0] && index[1]<N[1])
	{
		int tag = arrs[0][index[0]] <= arrs[1][index[1]]? 0:1;
		index[tag]++;
		count++;
		if(count==nMedian)
		{
			median = arrs[tag][index[tag]-(long int)1];
			break;
		}
	}
	if (count<nMedian)
	{
		median = arrs[1-tag][index[1-tag] + nMedian - count-(long int)1];
	}
	//cout<<index[0]<<" "<<index[1]<<" "<<median<<endl;
 	cout<<median<<endl;

	
	return 0;
}