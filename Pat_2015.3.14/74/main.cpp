#include <iostream>
#include <vector>
#include <map>

using namespace std;

class node
{
public:
	int _id;
	int _data;
	int _next;
	node(){}
	node( int id, int data, int next)
	{
		_id = id;
		_data = data;
		_next = next;
	}
	void output()
	{
		if(_next==-1)
		{
			printf("%05d %d %d\n", _id, _data, _next);
		}
		else
		{
			printf("%05d %d %05d\n", _id, _data, _next);
		}
	}
};
int main()
{
	freopen( "sample.in", "r", stdin);
	int root, N, K;
	cin>>root>> N>>K;

	int i;
	map< int, node> maps;
	for( i=0; i<N; ++i)
	{
		int id, data, next;
		cin>>id>>data>>next;

		maps[id] = node( id, data, next);
	}


	int pre = root;
	int cur = maps[pre]._next;
	for( i=1; i<K; ++i)
	{
		int tmpNext = maps[cur]._next;
		maps[cur]._next = pre;
		pre = cur;
		cur = tmpNext;
	}
	maps[root]._next = cur;

	//output
	cur = pre;
	while( cur != -1)
	{
		maps[cur].output();
		cur = maps[cur]._next;
	}
	return 0;
}