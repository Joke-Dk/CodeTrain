#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;


bool  cmp (pair< int , float> a, pair<int, float> b)
{
	return a.second >b.second;
}
int main()
{
	freopen( "sample.in", "r", stdin);
	int N, D;
	cin>>N>>D;

	int i;
	vector<pair< int, float> > sets;
	vector< float> amounts(N);
	vector< float> prices(N);
	for( i=0; i<N; ++i)
	{
		scanf("%f", &amounts[i]);
	}
	for( i=0; i<N; ++i)
	{
		scanf("%f", &prices[i]);
		sets.push_back( pair<int, float>( i, prices[i]/(float)amounts[i]));
	}
	sort( sets.begin(), sets.end(), cmp);
	float sumAmount = 0;
	float sumPrice = 0.f;
	vector< pair<int, float> >::iterator it;
	for( it = sets.begin(); it!=sets.end(); it++)
	{
		int id = it->first;
		//cout<<id<<endl;
		if( sumAmount + amounts[id]>=(float)D)
		{
			break;
		}		

		sumAmount += amounts[id];
		sumPrice += prices[id];
		
	}

	if( it!=sets.end())
	{
		int id = it->first;
		sumPrice += ((float)D-sumAmount)*prices[id]/amounts[id];
	}
	printf( "%.2f\n", sumPrice);
	return 0;
}