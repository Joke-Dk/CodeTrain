#include <iostream>
#include <vector>
using namespace std;

int record[10000][200];
vector<int> match;
vector<int> array;
int Dp( int n, int m)
{
	if(n==-1||m==-1){
		return 0;
	}
	if(record[n][m]>-1)
	{
		return record[n][m];
	}
	if(array[n] == match[m])
	{
		record[n][m] = Dp( n-1, m)+1;
		return record[n][m];
	}
	record[n][m] = max(Dp( n-1, m),Dp( n, m-1));
	return record[n][m];
}

int main()
{
	freopen( "sample.in", "r", stdin);
	
	int nColor;
	cin>>nColor;
	
	int M, N;
	cin>>M;
	match.resize(M);
	for( int i=0; i<M; ++i)
	{
		cin>>match[i];
	}
	cin>>N;
	array.resize(N);
	for( int i=0; i<N; ++i)
	{
		cin>>array[i];
	}
	
	for(int i=0; i<10000; i++)
	{
		for( int j=0; j<200; j++)
		{
			record[i][j] = -1;
		}
	}
	cout<<Dp( N-1, M-1)<<endl;
	
	return 0;
}