#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <stdio.h>
using namespace std;
const int MAX = 1000000;

class bank_queue
{
public:
	int _ID;
	int _min;
	int _time;
	bank_queue(int id, int min0)
	{
		_ID = id;
		_min = min0;
		_time = 0;
 	}

};
class bank
{
public:
	vector<queue<bank_queue*>*> arr_queue;
	vector<int> start_times;
	int line_contain; 
	int line_num;
	bool isfull;
	bool isempty;
	bank(int N, int M)
	{
		line_num = N;
		for(int i=0; i<N; i++)
		{
			arr_queue.push_back(new queue<bank_queue*>);
			start_times.push_back(0);
		}
		line_contain = M;
		isfull = 0;
		isempty = 1;
	}

	void equeue(bank_queue * q0)
	{
		if (isfull)
			return;

		int min_line_num = MAX;
		int min_line_num_index = -1;
		for (int i=0; i<line_num; i++)
		{
 			int size_tmp = arr_queue[i]->size();
			if(min_line_num > size_tmp)
			{
				min_line_num = size_tmp;
				min_line_num_index = i;
			}
		}

		//refresh this line queue
		arr_queue[min_line_num_index]->push(q0);

		//judge the bank is full
		isfull = 1;
		for (int i=0; i<line_num; i++)
		{
			if(arr_queue[i]->size()<line_contain)
			{
				isfull = 0;
				break;
			}
		}

		isempty = 0;
	}

	bank_queue* dqueue()
	{
		if(isempty) return NULL;

		int min_line_num = MAX;
		int min_line_num_index = -1;
		for (int i=0; i<line_num; i++)
		{
			if((*arr_queue[i]).size()==0)
				continue;
			int m_data = start_times[i]+(*arr_queue[i]).front()->_min;
			if(min_line_num > m_data)
			{
				min_line_num = m_data;
				min_line_num_index = i;
			}
		}

		//refresh this line queue
		start_times[min_line_num_index] = min_line_num;
		bank_queue* ret = (*arr_queue[min_line_num_index]).front();
		(*arr_queue[min_line_num_index]).pop();
		//judge the bank is full
		isempty = 1;
		for (int i=0; i<line_num; i++)
		{
			if(arr_queue[i]->size()>0)
			{
				isempty = 0;
				break;
			}
		}
		isfull = 0;

		ret->_time = min_line_num;
		return ret;

		
	}
};
int main()
{
	int N, M, K, Q;
	cin>>N>>M>>K>>Q;
	vector<bank_queue* > mins;
	for (int i=0; i<K; i++)
	{
		int tmp_min;
		cin>>tmp_min;
		mins.push_back(new bank_queue(i, tmp_min));
	}

	bank bank0(N, M);

	int ii = 0;
	while (1)
	{
		if (ii<mins.size() && !bank0.isfull )
		{
			bank0.equeue(mins[ii]);
			ii++;
		}
		else
		{
			if(bank0.isempty)
				break;
			bank0.dqueue();
		}
	}
		
	
	for (int i=0; i<Q; i++)
	{
		int query_index;
		cin>>query_index;
		int wait_time = mins[query_index-1]->_time;

		int cout_min = wait_time%60;
		int cout_hour = wait_time/60+8;
		if (cout_hour>=17 && cout_min!=0)
		{
			cout<<"Sorry"<<endl;
		}
		else
		{
			printf("%02d:%02d\n", cout_hour, cout_min);
		}
	}
	
	return 0;
}