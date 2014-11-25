#include<iostream>
#include<string>
using namespace std;
int main()
{
	int a,b;
	cin>>a>>b;
	int c=a+b;
	char chs[100];
	sprintf(chs,"%d",c);
	string str(chs);
	string ret=str;
	int start = 1;
	if (c<0) start = 2;
	for(int i=str.length()-3; i>=start;i-=3){
		ret.insert(i, ",");
	}
	cout<<ret<<endl;
	return 1;
}