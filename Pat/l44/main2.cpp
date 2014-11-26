#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> arrs;
vector<pair<int, int>> ret;
int minTotal = 1000000000;
int N, total;
void func()
{
	int i=0, j=0, tmpTotal=0;
	while( i<arrs.size())
	{
		while(tmpTotal<total&& j<arrs.size())
		{
			tmpTotal += arrs[j];
			j++;
		}
		if(tmpTotal>= total && tmpTotal<=minTotal)
		{
			if( tmpTotal<minTotal)
			{
				ret.clear();
				minTotal = tmpTotal;
			}
			ret.push_back( pair<int, int>(i+1, j));
			//cout<<i<<" "<<j<<" "<<tmpTotal<<" "<<minTotal<<endl;
		}
		
		tmpTotal -= arrs[i];
		i++;
		while( tmpTotal>total)
		{
			j--;
			tmpTotal -= arrs[j];
		}
	}
}

int main()
{
	freopen( "sample.in", "r", stdin);
	
	cin>>N>>total;
	
	arrs.resize( N);
	for( int i=0; i<N; ++i)
	{
		cin>>arrs[i];
	}
	func();
	
	for(int i=0; i<ret.size(); ++i)
	{
		cout<<ret[i].first<<"-"<<ret[i].second<<endl;
	}
	return 0;
}