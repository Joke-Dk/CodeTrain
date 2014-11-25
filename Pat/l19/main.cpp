#include <iostream>
#include <vector>
using namespace std;

int main()
{
	//freopen("sample.in","r", stdin);
	int N, radix;

	cin>>N>>radix;

	vector<int> output;

	int ret = N;
	
	if(N==0)
	{
		cout<<"Yes"<<endl<<N<<endl;
		return 0;
	}
	while(ret!=0)
	{
		output.push_back(ret%radix);
		ret /= radix;
	}

	bool flag_is = 1;
	//test whether digit is palindromic
	for(int i=0; i<output.size()/2; i++)
	{
		if(output[i] != output[output.size()-1-i])
		{
			flag_is = 0;
			break;
		}

	}

	if(flag_is)
	{
		cout<<"Yes"<<endl;
	}
	else
	{
		cout<<"No"<<endl;
	}
	
	int i = 0;
	for(i=0; i<output.size()-1; i++)
	{
		cout<<output[output.size()-1-i]<<" ";
	}
	
	cout<<output[0];

	return 0;

}