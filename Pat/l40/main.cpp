#include <iostream>
#include <string>

using namespace std;

bool judge(string str)
{
	for(int i=0; i<str.length()/2; i++)
	{
		if(str[i] != str[str.length()-1-i])
			return 0;
	}
	return 1;
}
int main()
{
	//freopen("sample.in", "r", stdin);
	string str;
	getline(cin, str);

	int max_len = 1;
	for(int i=0; i<str.length(); i++)
	{
		for(int j=max_len; j<=str.length()-i; j++)
		{
			if(judge(str.substr(i,j)))
				max_len = j;
		}
	}
	cout<<max_len<<endl;
	return 0;
}