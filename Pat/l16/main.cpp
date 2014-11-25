#include <iostream>
#include <string>
#include <stdio.h>
#include <unordered_map>
#include <algorithm>
using namespace std;

class record
{
public:
	int _times;
	int _arr_times[4];
	bool _flag;
	string _name;

	record(string name, int time, int flag, int* arr_times)
	{
		_name = name;
		_times = time;
		_flag = flag;
		//memcpy(_arr_times, arr_times, sizeof(int)*4);
		for (int i=0; i<4; i++)
		{
			_arr_times[i] = arr_times[i];
		}
	}


};

int units[4] = {30,24,60,1};
int str2time(string t, int* arr_times)
{
	int ret = 0;
	for (int i=0; i<4; i++)
	{
		string ss = t.substr(i*3, 2);
		char* chs = const_cast<char *>(ss.c_str());
		int dat = atoi(chs);
		if(i==0)
		{
			arr_times[3] = dat;
			continue;
		}
		arr_times[i-1] = dat;
		ret = ret*units[i-1] + dat;
	}
	
	return ret;
}

bool judge(string str)
{
	if(str == "on-line")//if(str.compare("on-line"))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool cmp_record(record r0, record r1)
{
	return r0._times<r1._times;
}

int costs[24];

float compute_cost(record r0, record r1)
{
	//r0<r1
	int *arr0 = r0._arr_times;
	int *arr1 = r1._arr_times;
	int ret = 0;

	//hour
	int h_begin = arr0[1];
	int h_end = (arr1[0]-arr0[0])*24+arr1[1];
	for (int i=h_begin+1; i<h_end; i++)
	{
		ret += costs[i%24]*60;
	}

	//min - begin
	ret += (60-arr0[2])*costs[h_begin%24];
	//min - end
	ret += arr1[2]*costs[h_end%24];

	return (float)ret/100.f;
}

int main()
{
	//freopen("sample.in","r", stdin);

	for (int i=0; i<24; i++)
	{
		cin>>costs[i];
	}

	unordered_map<string, vector<record>> umaps;

	
	int O;
	cin>>O;
	for (int i=0; i<O; i++)
	{
		string str_name;
		string str_time;
		string flag;
		cin>>str_name>>str_time>>flag;

		bool find_flag = umaps.find(str_name)!=umaps.end();
		int tmp_arr_time[4];
		int tmp_time = str2time(str_time, tmp_arr_time);
		record tmp_record(str_name, tmp_time, judge(flag), tmp_arr_time);
		if (!find_flag)
		{
			vector<record> v0;
			v0.push_back(tmp_record);
			umaps[str_name] = v0;
		}
		else
		{
			umaps[str_name].push_back(tmp_record);
		}
	}

	for(unordered_map<string, vector<record>>::iterator it = umaps.begin(); it!=umaps.end(); it++)
	{
		sort(it->second.begin(), it->second.end(), cmp_record );

		//find the pair <on-line:off-line> - cut the non-pair record
		vector<record>& v0 = it->second;
		for (int i=0; i<v0.size(); i++)
		{
			if (i==v0.size()-1 || (!(v0[i]._flag==1 && v0[i+1]._flag==0)))
			{
				v0.erase(v0.begin()+i);
				i--;
			}
			else
			{
				i++;
			}
		}
	}

	//sort the record
	vector<record> month_record;
	for(unordered_map<string, vector<record>>::iterator it = umaps.begin(); it!=umaps.end(); it++)
	{
		vector<record>& v0 = it->second;
		if (v0.size()!=0)
		{
			month_record.push_back(it->second[0]);
		}
	}
	sort(month_record.begin(),month_record.end(), cmp_record);

	//print
	for (int i=0; i<month_record.size(); i++)
	{
		cout<<month_record[i]._name;
		printf(" %02d\n", month_record[i]._arr_times[3]);

		float sum_cost = 0.f;
		vector<record>& v0 = umaps[month_record[i]._name];
		for (int j=0; j<v0.size(); j+=2)
		{
			printf("%02d:%02d:%02d " ,v0[j]._arr_times[0],v0[j]._arr_times[1], v0[j]._arr_times[2]);
			printf("%02d:%02d:%02d " ,v0[j+1]._arr_times[0],v0[j+1]._arr_times[1], v0[j+1]._arr_times[2]);
			cout<<v0[j+1]._times-v0[j]._times;
			float tmp_cost = compute_cost(v0[j], v0[j+1]);
			sum_cost += tmp_cost;
			printf(" $%.2f", tmp_cost);
			cout<<endl;
		}
		printf("Total amount: $%.2f\n", sum_cost);
	}

	return 0;

}