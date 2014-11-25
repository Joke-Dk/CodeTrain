#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX = 1000000;

class node
{
public:
	int id;
	vector<node*> neighbour;
	int len;
	node(int i)
	{
		id = i;
		len = -1;
	}
};

vector<node*> tree;

void clear_len()
{
	for(int i=0; i<tree.size(); i++)
		tree[i]->len = -1;
}


bool travel(node* node0, node* pre, int len0)
{
	node0->len = len0;
	for (int i=0; i<node0->neighbour.size(); i++)
	{
		node* tmp = node0->neighbour[i]; 
		if (tmp==pre)
			continue;
		if(tmp->len>-1)
			return 0;
		if (!travel(tmp, node0, len0+1))
		{
			return 0;
		}

	}
	return 1;
}

bool find_max_depeh(node* node0, int& max_len)
{
	max_len = 0;
	if(!travel(node0, NULL, 0))
		return 0;
	for (int i=0; i<tree.size(); i++)
	{
		if(max_len<tree[i]->len)
		{
			max_len = tree[i]->len;
		}
	}
	return 1;
}

int main()
{
	//freopen("sample.in","r", stdin);
	
	int N;
	cin>> N;

	for (int i=0; i<N; i++)
	{
		tree.push_back(new node(i));
	}

	int n0, n1;
	for (int i=0; i<N-1; i++)
	{
		cin>>n0>>n1;
		tree[n0-1]->neighbour.push_back(tree[n1-1]);
		tree[n1-1]->neighbour.push_back(tree[n0-1]);

	}
	bool flag_circle = 0;
	int final_max = 0;
	vector<int> ret;
	for (int i=0; i<N; i++)
	{
		int max_depth = 0;
		clear_len();
		if(find_max_depeh(tree[i], max_depth))
		{
			if(final_max==max_depth)
			{
				ret.push_back(i);
			}
			else if(final_max<max_depth)
			{
				final_max = max_depth;
				ret.clear();
				ret.push_back(i);
			}

		}
		else
		{
			flag_circle = 1;
			break;
		}
	}

	if(flag_circle)
		cout<<"Error: 2 components"<<endl;
	else
	{
		for (int i = 0; i < ret.size(); i++)
		{
			cout<<ret[i]+1<<endl;
		}
	}

	return 0;
}