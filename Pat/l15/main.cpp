#include <iostream>
#include <string>
#include <vector>
using namespace std;

int converse(int value0, int radix)
{
	vector<int> c0;
	int tmp = value0;
	while(tmp!=0)
	{
		c0.push_back(tmp%radix);
		tmp/=radix;
	}

	//get the elements of the c0 is the string()
	int ret = 0;
	for (int i=0; i<c0.size(); i++)
	{
		ret = ret*radix+c0[i];
	}
	return ret;
}

bool judgePrime(int v)
{
	if(v<2) return 0;
	bool ret = 1;
	for(int i=2; i<v/2; i++)
	{
		if (v%i==0)
		{
			ret = 0;
			break;
		}
	}
	return ret;
}

int main()
{
	int a = 0, b=0;
	while (1)
	{
		cin>>a;
		if (a<0) break;

		cin>>b;
		int reverse_int = converse(a, b);
		if (judgePrime((reverse_int)))
		{
			cout<<"Yes"<<endl;
		}
		else
		{
			cout<<"No"<<endl;
		}
		
	}
	return 0;

}