#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	freopen("sample.in", "r", stdin);
	int N;
	cin>>N;
	getchar();
	vector<string> arrs;
	int minLen = 100000;
	for( int i=0; i<N; ++i)
	{
		string	str;
		getline( cin, str);
		arrs.push_back( str);
		if(minLen>str.length())
		{
			minLen = str.length();
		}
	}

	int commenLen = 0;
	bool flag = 0;
	//solve
	for( int i=0; i<minLen; ++i)
	{
		char top = arrs[0][arrs[0].length()-1-i];
		for( int j=0; j<N; ++j)
		{
			char cur = arrs[j][arrs[j].length()-1-i];
			if(top!=cur)
			{
				flag = 1;
				break;
			}
		}
		if(flag)
		{
			break;
		}
		commenLen++;
	}

	if(commenLen==0)
	{
		cout<<"nai"<<endl;
	}
	else
	{
		string ret = arrs[0].substr( arrs[0].length()-commenLen, commenLen);
		cout<<ret<<endl;
	}
	return 0;

}