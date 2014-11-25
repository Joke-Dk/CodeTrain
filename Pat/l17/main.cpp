#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<queue>  
using namespace std;

class customer
{
public:
	int _time;
	int _occupy;

	customer(int time, int occupy)
	{
		_time = time;
		_occupy = occupy;
	}

	bool operator < (const customer& c0) const
	{
		return _time>c0._time;
	}
};


int str2time(string str)
{
	int ret = 0;
	for (int i=0; i<3; i++)
	{
		int tmp_int = atoi( const_cast<char*>(str.substr(i*3, 2).c_str()));
		ret = ret*60+tmp_int;
	}
	return ret;
}




int main()
{
	//freopen("sample.in","r", stdin);
	int N, M;
	cin>>N>>M;
	int start_work = 8*3600;
	int end_work = 17*3600;

	priority_queue<customer> bank_windows;
	for( int i=0; i<M; i++)
	{
		bank_windows.push(customer(start_work, 0));
	}
	priority_queue<customer> arr_customers;
	for (int i=0; i<N; i++)
	{
		string arrive_time;
		int occupy_time;
		cin>>arrive_time>>occupy_time;
		arr_customers.push(customer(str2time(arrive_time), occupy_time));
	}

	int ret = 0;
	int customer_n = 0;
	while (!arr_customers.empty())
	{
		customer w_first = bank_windows.top();
		customer cur_customer = arr_customers.top();

		
		if (cur_customer._time>end_work)
		{
			break;
		}
		customer_n++;
		arr_customers.pop();
		bank_windows.pop();
		//wait
		if (cur_customer._time<w_first._time)
		{
			ret += w_first._time - cur_customer._time;
			
		}
		cur_customer._time = max(cur_customer._time, w_first._time) + cur_customer._occupy*60;
		bank_windows.push(cur_customer);
	}
	
	printf("%.1f",(float)ret/(float)customer_n/60.f);

	return 0;
}
