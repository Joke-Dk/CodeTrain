#include <iostream>
#include <string>


using namespace std;
char ch[5] = {'S', 'H', 'C', 'D', 'J'}; 
int main()
{
	//freopen("sample.in", "r", stdin);

	string strs[54];
	for(int i=0; i<54; i++)
	{

		strs[i] = ch[i/13]+ to_string(i%13+1);
	}

	int N;
	cin>>N;
	int indexs[54];
	for(int i=0; i<54; i++)
	{
		cin>>indexs[i];
	}

	string tmp_strs[54];
	for(int j=0; j<N; j++)	
	{
		for(int i=0; i<54; i++)
		{
			tmp_strs[i] = strs[i];
		}

		for(int i=0; i<54; i++)
		{
			strs[indexs[i]-1] = tmp_strs[i];
		}
	}

	cout<<strs[0];
	for(int i=1; i<54; i++)
	{
		cout<<" "<<strs[i];
	}
	cout<<endl;
	return 0;
}