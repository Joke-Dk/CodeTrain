#include <iostream>
#include <string>
using namespace std;



int main()
{
	char str[4] = "WTL";
	float odds[9];
	for (unsigned int i=0; i<9; i++)
	{
		cin>>odds[i];
	}

	float ret = 1.f;
	for (unsigned int i=0; i<3; i++)
	{
		float game_max = 0;
		int index_max = -1;
		for (unsigned int j=0; j<3; j++)
		{
			if (odds[i*3+j]>game_max)
			{
				index_max = j;
				game_max = odds[i*3+j];
			}
			
		}
		ret*=game_max;
		cout<<str[index_max]<<" ";
	}
	ret = (ret*0.65f-1.f)*2.f;
	//cout<<ret;
	ret += 0.005f;
	printf("%.2f", ret);
	return 0;
}