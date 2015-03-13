#include <cstdio> 
using namespace std;

int main()
{
	freopen("sample.in", "r", stdin);
	int N;
	scanf("%d",&N);  
	for( int i=0; i<N; ++i)
	{
		//cout<<"Case #"<<i+1<<": ";
		bool tag = 1;
		long long a, b, c;
		scanf("%lld %lld %lld",&a,&b,&c);  ;
		long long res = a+b; 
		if(a>0&&b>0&&(a+b)<=0)
		{
			tag = 1;
		}
		else if(a<0&&b<0&&(a+b)>=0)
		{
			tag = 0;
		}
		else if((a+b)<=c)
		{
			tag = 0;
		}
		
		if(tag){  
            printf("Case #%d: true\n",i+1);  
        }else{  
            printf("Case #%d: false\n",i+1);  
        }  
	}
	return 0;
}