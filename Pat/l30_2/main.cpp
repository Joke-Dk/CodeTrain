#include <iostream>
#include <vector>

using namespace std;
const int MAX = 500;
const int INF =  100000;
int Distances[MAX*MAX];
int Cost[MAX*MAX];

int N, M;
int id_start, id_end;
int len[MAX];
bool visited[MAX];
int index(int x, int y)
{
	return x*N+y;
}

void dijstrak()
{
	for (int i=0; i<N; i++)
	{
		len[i] = INF;
		visited[i] = 0;
	}
	int cur_id = id_start;
	len[cur_id] = 0;
	for (int i=0; i<N; i++)
	{
		visited[cur_id] = 1;
		//fresh current_id near cities length
		for(int j=0; j<N; j++)
		{
			if (!visited[j] && Distances[index(cur_id, j)]!=INF)
			{
				if (len[j]>len[cur_id]+Distances[index(cur_id, j)])
				{
					len[j]=len[cur_id]+Distances[index(cur_id, j)];
				}
			}
		}

		int min_len = INF;
		//find the min city_id
		for(int j=0; j<N; j++)
		{
			if (!visited[j] && len[j]<min_len)
			{
				min_len = len[j];
				cur_id = j;
			}
		}
	}

}

void clear_visited()
{
	for (int i=0; i<N;i++)
	{
		visited[i] = 0;
	}
}
int cur_paths[MAX];
int min_paths[MAX];
int min_len = 0 ;
int min_cur_cos = INF;
int min_step = 0;
void find_all_road(int cur_id, int step, int pre_len)
{
	cur_paths[step] = cur_id;
	visited[cur_id] = 1;

	//compute min_len
	min_len += pre_len;

	if(min_len == len[id_end] && cur_id==id_end)
	{
		int cur_cost = 0;
		for(int i=0; i<step; i++)
		{
			cur_cost += Cost[index(cur_paths[i], cur_paths[i+1])];
		}
		if(cur_cost<min_cur_cos)
		{
			min_cur_cos = cur_cost;
			for (int i=0; i<step+1; i++)
			{
				min_paths[i] = cur_paths[i];
			}
			min_step = step;
		}
	}
	else
	{

		for (int i=0; i<N; i++)
		{
			if(!visited[i] && Distances[index(cur_id, i)]!=INF)
			{
				find_all_road(i, step+1, Distances[index(cur_id, i)]);
				//visited[i] = 0;
			}
		}
	}

	min_len -= pre_len;

	visited[cur_id] = 0;

}
int main()
{
	//freopen("sample.in", "r", stdin);


	cin>>N>>M>> id_start>>id_end;

	for (int i=0; i<N*N; i++)
	{
		Distances[i] = INF;
		Cost[i] = INF;
	}

	for(int i=0; i<M; i++)
	{
		int tmp1, tmp2, tmp_dis, tmp_cos;
		cin>>tmp1>>tmp2>>tmp_dis>>tmp_cos;
		Cost[index(tmp1, tmp2)] = tmp_cos;
		Cost[index(tmp2, tmp1)] = tmp_cos;
		Distances[index(tmp1, tmp2)] = tmp_dis;
		Distances[index(tmp2, tmp1)] = tmp_dis;
	}


	dijstrak();
	clear_visited();
	find_all_road( id_start, 0, 0);

	for (int i=0; i<min_step+1; i++)
	{
		cout<<min_paths[i]<<" ";
	}
	cout<<len[id_end]<<" "<<min_cur_cos<<endl;
	return 0;
}