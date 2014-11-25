#include <iostream>
#include <vector>
using namespace std;

class dnode
{
public:
	int ID;
	bool visited;
	vector<dnode*> neighbour;
	dnode(int _ID)
	{
		ID = _ID;
		visited = 0;
	}
};

void travel(dnode* node0)
{
	if (node0->visited) return;
	node0->visited = 1;
	for (int i=0;i<node0->neighbour.size(); i++)
	{
		travel(node0->neighbour[i]);
	}
}

void clear(vector<dnode*>& phead)
{
	for (int i=0; i<phead.size(); i++)
	{
		phead[i]->visited = 0;
	}
}
int main()
{
	int N, M, O;
	cin>>N>>M>>O;
	vector<dnode*> phead;
	for(int i=0; i<N; i++)
	{
		phead.push_back(new dnode(i));
	}

	for (int i=0; i<M; i++)
	{
		int a,b;
		cin>>a>>b;
		phead[a-1]->neighbour.push_back(phead[b-1]);
		phead[b-1]->neighbour.push_back(phead[a-1]);
	}

	for (int i=0; i<O; i++)
	{
		int seperate = 0;
		int enemy;
		cin>>enemy;
		enemy--;
		phead[enemy]->visited = 1;
		for (int j=0; j<phead.size(); j++)
		{
			if(j!=enemy&&!phead[j]->visited)
			{
				travel(phead[j]);
				seperate++;
			}
		}
		cout<<seperate-1<<endl;
		clear( phead);

	}
	return 0;
}

