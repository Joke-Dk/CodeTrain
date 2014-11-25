#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arrs[2];
vector<int> rets[4];
bool judge(int a)
{
	return a>0;
}
void split_arrs(int index)
{
	sort(arrs[index].begin(), arrs[index].end(), less<int>());
	vector<int>::iterator fi= find_if(arrs[index].begin(), arrs[index].end(), judge);
	rets[index*2+0] = vector<int>(arrs[index].begin(), fi);
	rets[index*2+1] = vector<int>(fi, arrs[index].end());
	reverse(rets[index*2+1].begin(), rets[index*2+1].end());
}
int main()
{
	//freopen("sample.in","r", stdin);



	int N1, N2;
	cin>>N1;
	for(int i=0; i<N1; i++)
	{
		int tmp;
		cin>>tmp;
		arrs[0].push_back(tmp);
	}
	cin>>N2;
	for(int i=0; i<N2; i++)
	{
		int tmp;
		cin>>tmp;
		arrs[1].push_back(tmp);
	}

	for(int i=0; i<2; i++)
	{
		split_arrs(i);
	}

	int result = 0;
	//positive
	for(int i=0; i<min(rets[1].size(), rets[3].size()); i++)
	{
		result += rets[1][i]*rets[3][i];
	}
	//<0
	for(int i=0; i<min(rets[0].size(), rets[2].size()); i++)
	{
		result += rets[0][i]*rets[2][i];
	}
	cout<<result<<endl;
	return 0;
}