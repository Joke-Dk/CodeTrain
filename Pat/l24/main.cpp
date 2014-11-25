#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool isPalindromic(int digit)
{
	vector<int> tmp;
	while(digit!=0)
	{
		tmp.push_back(digit%10);
		digit /= 10;
	}

	for(int i=0; i<tmp.size()/2; i++)
	{
		if(tmp[i] != tmp[tmp.size()-1-i])
			return 0;
	}

	return 1;
}

void doubleone(int & digit0)
{
	// get reverse one
	int digit = digit0;
	vector<int> tmp;
	while(digit!=0)
	{
		tmp.push_back(digit%10);
		digit /= 10;
	}

	int digit1 = 0;
	for(int i=0; i<tmp.size(); i++)
	{
		digit1 = digit1*10 + tmp[i];
	}

	digit0 += digit1;

}

int main()
{
	//freopen( "sample.in", "r", stdin);

	int N, K;
	cin>>N>>K;

	int i=0;
	for(i=0; i<K; i++)
	{
		bool flag0 = isPalindromic(N);
		if(flag0)
		{
			break;
		}
		doubleone(N);
	}

	cout<<N<<endl<<i<<endl;

	return 0;
	
}