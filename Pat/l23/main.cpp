#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


unsigned long long str2long(string str)
{
	unsigned long long ret = 0;
	for(int i=0; i<str.length(); i++)
	{
		ret = ret*10+atoi( const_cast<char *>(str.substr(i, 1).c_str()));
	}
	return ret;
}

string long2str(unsigned long long digit)
{
	if(digit==0)
		return "0";

	vector<int> arr_digit; 
	unsigned long long tmp = digit;
	while(tmp!=0)
	{
		arr_digit.push_back(tmp%10);
		tmp /= 10;
	}
	char *chs = new char[arr_digit.size()+1];
	reverse(arr_digit.begin(), arr_digit.end());
	for(int i=0; i<arr_digit.size(); i++)
	{
		chs[i] = '0'+arr_digit[i];
	}
	chs[arr_digit.size()] = '\0';
	string ret_str(chs);
	return ret_str;
}

bool test_double(string str0, string str1)
{
	int flag0[10], flag1[10];
	for(int i=0; i<10; i++)
	{
		flag0[i] = 0;
		flag1[i] = 0;
	}
	for(int i=0; i<str0.length(); i++)
	{
		int tmp = str0[i] - '0';
		flag0[tmp]++;
	}

	for(int i=0; i<str1.length(); i++)
	{
		int tmp = str1[i] - '0';
		flag1[tmp]++;
	}

	for(int i=0; i<10; i++)
	{
		if(flag0[i] != flag1[i])
			return 0;
	}
	return 1;
}

int main()
{
	//freopen( "sample.in", "r", stdin);

	string str0;
	cin>>str0;

	unsigned long long tmplong = str2long(str0);

	tmplong *= 2;

	string tmp_str = long2str(tmplong);

	bool isdoubel = test_double(str0, tmp_str);

	string str_out = isdoubel?"Yes":"No";

	cout<<str_out<<endl<<tmp_str<<endl;

	return 0;
}