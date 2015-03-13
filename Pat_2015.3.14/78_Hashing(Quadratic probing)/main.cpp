#include <iostream>
#include <vector>

using namespace std;

bool judgePrime( int a)
{
	if(a==1 || a==0)
	{
		return 0;
	}
	for( int i=2; i<=a/2; ++i)
	{
		if( a%i==0)return 0;
	} 
	return 1;
}

int main()
{
	freopen( "sample.in", "r", stdin);
	int M, N;
	cin>>M>>N;
	while(1)
	{
		if(judgePrime(M))
		{
			break;
		}
		M++;
	}
	//cout<<M<<endl;
	vector<bool> arrs(M, false);
	for( int i=0; i<N; ++i)
	{
		if(i!=0)
		{
			cout<<" ";
		}

		int tmp;
		scanf("%d", &tmp);
		//Judge
		int index=-1;
		for( int j=0; j<M; ++j)
		{
			if (!arrs[(tmp+j*j)%M])
			{
				index = (tmp+j*j)%M;
				break;
			}
		}
		if( index==-1)
		{
			cout<<"-";
		}
		else
		{
			cout<<index;
			arrs[index] = 1;
		}
		
	}
	return 0;
}