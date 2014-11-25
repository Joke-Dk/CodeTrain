#include <iostream>
#include <vector>
using namespace std;


int main()
{
	//freopen("sample.in", "r", stdin);
	int n;
	cin>>n;
	vector<int> distance;
	distance.resize( n+1);
	distance[0] = 0;
	int tmpI;
	for(int i=1; i<n+1; i++)
	{
		cin>>tmpI;
		distance[i] = distance[i-1] + tmpI;
	}
	
	int N;
	cin>>N;
	int a, b;
	for( int i=0; i<N; i++)
	{
		cin>>a>>b;
		int len1 = distance[max(a-1, b-1)] - distance[min(a-1, b-1)];
		int len2 = distance[n] - len1;
		cout<<min( len1, len2)<<endl;
	}
	
	

	return 0;
}