#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 100000;

class station
{
public:
	float _cost;
	float _dis;
	station(float cost, float dis)
	{
		_cost = cost;
		_dis = dis;
	}
};

bool cmp_station(station* s1, station* s2)
{
	return s1->_dis<s2->_dis;
}

vector<station *> arrs;
float Tank, dis_end, per_cost;
int N;
float each_dis;

float cur_gas;
float cur_dis;
float sum_gas;
float sum_cos;

bool judge(int& cur_id)
{
	//find the last id in the max distance for one time
	int last_id = cur_id;
	for(last_id=cur_id; last_id<N; last_id++)
	{
		if(arrs[last_id]->_dis-arrs[cur_id]->_dis>each_dis)
		{
			break;
		}
	}

	last_id--;
	if(last_id == cur_id)
	{
		//full it
		sum_gas += Tank-cur_gas;
		cur_dis = arrs[cur_id]->_dis+(Tank-cur_gas)*per_cost;
		sum_cos += (Tank-cur_gas)*arrs[cur_id]->_cost;
		cur_gas = 0;
		return 0;//finish
	}

	//Judge whether gas[cur+1]...gas[last] > gas[cur]
	int min_id = cur_id;
	float min_cost = arrs[cur_id]->_cost;
	for(int i = cur_id+1; i<=last_id; i++)
	{
		if(min_cost > arrs[i]->_cost)
		{
			min_id = i;
			min_cost = arrs[i]->_cost;
		}
	}

	
	if(min_id == cur_id)
	{
		//full it
		//gas[cur+1]...gas[last] > gas[cur]
		//advance to-> gas[cur+1]
		sum_gas += Tank - cur_gas;
		sum_cos += (Tank-cur_gas)*arrs[cur_id]->_cost;
		cur_id++;
		cur_gas = Tank - (arrs[cur_id]->_dis-arrs[cur_id-1]->_dis)/per_cost;
		cur_dis = arrs[cur_id]->_dis;
		return 1;//go on
	}

	//min_id != cur_id
	// there is i for gas[min_id] < gas[cur]
	//arrive to -> gas[min_id]
	cur_dis = arrs[min_id]->_dis;
	float off_gas = (arrs[min_id]->_dis - arrs[cur_id]->_dis)/per_cost-cur_gas;
	float add_gas = off_gas>0?off_gas:0;

	sum_gas += add_gas;
	sum_cos += add_gas*arrs[cur_id]->_cost;
	cur_gas = off_gas<0? -off_gas:0;
	cur_id = min_id;
	return 1;//go on
}
int main()
{
	freopen("sample.in", "r", stdin);
	
	cin>>Tank>>dis_end>>per_cost>>N;
	
	each_dis = Tank * per_cost;

	for(int i=0; i<N; i++)
	{
		float cost;
		int dis_road;
		cin>>cost>>dis_road;
		arrs.push_back(new station(cost, dis_road));

	}
	arrs.push_back(new station(INF, dis_end));

	sort(arrs.begin(), arrs.end(), cmp_station);
	N++;

	sum_gas = 0;
	sum_cos = 0;             
	int cur_id = 0;
	bool flag_has_gas = 1;
	while(cur_id<N-1)
	{
		flag_has_gas = judge(cur_id);
		if(!flag_has_gas)
		{
			break;
		}
	}

	return 0;
}