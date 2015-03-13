#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

long N, p;
vector<long> arrs;
long maxLength = 0;
void FindLongest()
{
	long i=0, j=0;
	while( i<N&&j<N)
	{
		while(j<N && arrs[j]<=arrs[i]*p)
		{
			j++;
		}
		if(j-i+1>maxLength)
		{
			maxLength = j-i;
		}
		i++;
	} 	
}

int main()
{
	freopen( "sample.in", "r", stdin);
	cin>>N>>p;
	for(long i=0; i<N; i++)
	{
		long tmpI;
		scanf("%ld", &tmpI);
		arrs.push_back( tmpI);
	}
	sort( arrs.begin(), arrs.end());
	//for(long i=0; i<arrs.size(); ++i)
	//{	
	//	prlongf("%d ", arrs[i]);
	//}
	FindLongest();
	cout<<maxLength<<endl;
	return 0;
}
