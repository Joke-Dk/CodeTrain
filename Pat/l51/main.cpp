#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
#define REP(i, n) for(int i=0; i<n; ++i)

int head = 0;
bool judge(int a)
{
	return a>head;
}

int M,N,K;
bool test(vector<int>& arrs)
{
	if(arrs.size()<=1)
		return 1;

	head = arrs[0];
	vector<int>::iterator it = find_if(arrs.begin()+1, arrs.end(), judge);
	vector<int> arr1(arrs.begin()+1, it);
	vector<int> arr2(it, arrs.end());
	if(arr1.size()>=M) return 0;

	//vector<int>::size_type size0 = arr1.size()-1;
	for(int i=1; i<arr1.size(); i++)
	{
		if(arr1[i-1] <= arr1[i])
			return 0;
	}
	return test(arr2);

}
int main()
{
	//freopen("sample.in", "r", stdin);


	cin>>M>>N>>K;
	vector<int> arrs;
	REP(i, K)
	{
		REP(j, N)
		{
			int tmp;
			cin>>tmp;
			arrs.push_back(tmp);
		}
		bool flag = test(arrs);
		string str = flag?"YES":"NO";
		cout<<str<<endl;
		arrs.clear();
	}
	return 0;

}