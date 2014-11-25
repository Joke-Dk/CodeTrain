#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
	//freopen("sample.in", "r", stdin);
	int H1, H2, N;
	cin>>H1>>H2>>N;

	unordered_map<int, int> umaps;
	for(int i=0; i<N; i++)
	{
		int add0, add1;
		string ch;
		cin>>add0>>ch>>add1;

		if(umaps.find(add1)==umaps.end())
		{
			umaps[add1] = 1;
		}
		else
		{
			umaps[add1] += 1;
		}
	}
	
	for(unordered_map<int, int>::iterator it = umaps.begin(); it!=umaps.end(); it++)
	{
		if(it->second == 2)
			cout<<it->first<<endl;
	}
	
	return 0;
}