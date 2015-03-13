#include <string>
#include <map>
#include <iostream>
#include <cstring>

using namespace std;

const int INF = 2100000000;
const int MAX = 205;
int n, K;
bool vi[MAX];
int dis[MAX];
int cost[MAX][MAX];
int happiness[MAX], final_happiness[MAX];
int pre[MAX];
int pre_city_cnt[MAX];
int road_cnt[MAX];
map<string, int> name_to_num;
map<int, string> num_to_name;

void init()
{
	string name1, name2;
	int dist;
	cin >> n >> K >> name1;
	name_to_num[name1] = 0;
	num_to_name[0] = name1;
	happiness[0] = final_happiness[0] = 0;
	for (int i = 1; i < n; ++ i)
	{
		cin >> name1;
		name_to_num[name1] = i;
		num_to_name[i] = name1;
		cin >> happiness[i];
	}
	memset(vi, false, sizeof(vi));
	memset(road_cnt, 0, sizeof(road_cnt));
	memset(pre_city_cnt, 0, sizeof(pre_city_cnt));
	for (int i = 0; i < n; ++ i)
	{
		dis[i] = INF;
		for (int j = 0; j < n; ++ j)
		{
			cost[i][j] = INF;
		}
	}
	for (int i = 0; i < K; ++ i)
	{
		cin >> name1 >> name2 >> dist;
		cost[name_to_num[name1]][name_to_num[name2]] = dist;
		cost[name_to_num[name2]][name_to_num[name1]] = dist;
	}
}

void dijkstra()
{
	dis[0] = 0;
	road_cnt[0] = 1;

	for (int k = 0; k < n; ++ k)
	{
		int index = -1;
		int minn = INF;
		for (int i = 0; i < n; ++ i)
		{
			if (vi[i]==false && dis[i]<minn)
			{
				index = i;
				minn = dis[i];
			}
		}
		if (index == -1)
		{
			break;
		}
		vi[index] = true;
		for (int j = 0; j < n; ++ j)
		{
			if (dis[j] > dis[index] + cost[index][j])
			{
				road_cnt[j] = road_cnt[index];				
				dis[j] = dis[index] + cost[index][j];
				final_happiness[j] = final_happiness[index] + happiness[j];	
				pre_city_cnt[j] = pre_city_cnt[index] + 1;
				pre[j] = index;
			} else if (dis[j] == dis[index] + cost[index][j])
			{
				road_cnt[j] += road_cnt[index];
				if (final_happiness[j] < final_happiness[index] + happiness[j])
				{
					final_happiness[j] = final_happiness[index] + happiness[j];
					pre_city_cnt[j] = pre_city_cnt[index] + 1;
					pre[j] = index;
				} else if (final_happiness[j] == final_happiness[index] + happiness[j]
					&& pre_city_cnt[j] > pre_city_cnt[index] + 1)
				{
					pre_city_cnt[j] = pre_city_cnt[index] + 1;
					pre[j] = index;
				}
			}
		}
	}
}

void print(int city)
{
	if (city == 0)
	{
		int dest = name_to_num[string("ROM")];
		cout << road_cnt[dest] << " " << dis[dest] << " "
			<< final_happiness[dest] << " " << final_happiness[dest] / pre_city_cnt[dest] << endl;
		cout << num_to_name[0];
	} else 
	{
		print(pre[city]);
		cout << "->" << num_to_name[city];
	}
}

int main()
{
	init();

	dijkstra();

	print( name_to_num[string("ROM")] );

	return 0;
}