#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool cmp(string s1, string s2)
{
	bool flag_move = 0;
	while(1)
	{
		string tmp;

		//make sure len(s1) <= len(s2)
		if(s1.length()>s2.length())
		{
			tmp = s1;
			s1 = s2;
			s2 = tmp;
			flag_move = !flag_move;
		}

		int i;
		for(i=0; i<min(s1.length(),s2.length()); i++)
		{
			if(s1[i]!=s2[i])
			{
				bool ret = flag_move?s1[i]>s2[i]:s1[i]<s2[i];
				return ret;
			}
		}

		if(s1.length() == s2.length())
			return 0;
		//if all the same
		s2 = s2.substr(i);
	}
}

string cut(string str)
{
	string str2;
	int i;
	for(i=0; i<str.length(); i++)
		if(str[i]!='0')
			break;
	str2 = str.substr(i);
	return str2;
}
int main()
{
	//freopen("sample.in", "r", stdin);

	int N;
	cin>>N;
	vector<string> arrs;
	for(int i=0; i<N; i++)
	{
		string tmp;
		cin>>tmp;
		arrs.push_back(tmp);
	}

	sort(arrs.begin(), arrs.end(), cmp);
	string rets;
	int ii=0;
	for(ii=0; ii<arrs.size(); ii++)
	{
		if(cut(arrs[ii])!="")
			break;
	}
	for(int i=ii; i<arrs.size(); i++)
	{
		if(i==ii)
			rets.append(cut(arrs[i]));
		else
			rets.append(arrs[i]);
	}
	if(rets.length()!=0)
		cout<<rets<<endl;
	else
		cout<<"0"<<endl;
	return 0;
}