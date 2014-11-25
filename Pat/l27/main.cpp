#include <iostream>
#include <string>

using namespace std;

int char2digit(char ch)
{
	if(ch<='9' && ch>='0')
		return ch-'0';
	else
		return ch-'A'+10;
}

char digit2char(int val)
{
	if(val<=9)
		return '0'+val;
	else
		return 'A'+val-10;
}

string radix(int color)
{
	int ret = color;
	
	char chs[3];
	chs[0] = digit2char(ret/13 );
	chs[1] = digit2char(ret%13 );
	chs[2] = '\0';
	return string(chs);
}

int main()
{
	//freopen("sample.in", "r", stdin);
	int RGB[3];
	string colors;
	for(int i=0; i<3; i++)
	{
		cin>>RGB[i];
		string tmp = radix(RGB[i]);
		colors.insert(colors.end(), tmp.begin(), tmp.end());
	}

	cout<<"#"<<colors<<endl;

	return 0;
}