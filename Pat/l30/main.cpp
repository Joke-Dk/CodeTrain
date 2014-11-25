#include <iostream>
#include <vector>

using namespace std;

class city
{
public:
	int _id;
	int _dis;
	int _cos;
	bool _visited;

	vector<city*> _near;

	city(int id, int dis, int cos)
	{
		_id = id;
		_dis = dis;
		_cos = cos;
		_visited = 0;
	}

};

class load
{
public:
	city* dest;

};

vector<city*> cities;


int main()
{
	freopen("sample.in", "r", stdin);

	int N, M;
	int id_start, id_end;

	cin>>N>>M>> id_start>>id_end;

	for(int i=0; i<M; i++)
	{

	}
}