#include <iostream>
#include <vector>

using namespace std;

vector<long int> ss[2];
int index[2];

long int indx(int i, int offset)
{
	return ss[i][index[i]+offset];
}
int main()
{
	//freopen( "sample.in", "r", stdin);

	int N1;
	cin>>N1;
	for(int i=0; i<N1; i++)
	{
		long int tmp;
		cin>>tmp;
		ss[0].push_back(tmp);
	}

	int N2;
	cin>>N2;
	for(int i=0; i<N2; i++)
	{
		long int tmp;
		cin>>tmp;
		ss[1].push_back(tmp);
	}

	//find the median of two sequences
	index[0] = 0; index[1] = 0;
	int curr_i = 0;
	if(indx(1, 0)<indx(0, 0))
		curr_i = 1;
	while(index[0]+index[1]+1<(N1+N2+1)/2)
	{
		if(indx(curr_i, 1)>indx(1-curr_i, 0))
		{
			curr_i = 1-curr_i;
		}
		index[curr_i]++;

	}

	int ret = index[0]+index[1];

	cout<<indx(curr_i, 0);
	return 0;  
}