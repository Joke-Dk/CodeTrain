#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class node
{
public:
	long _id;
	long _data;
	long _next;
	node(){}
	node( long id, long data, long next)
	{
		_id = id;
		_data = data;
		_next = next;
	} 
	void output()
	{
		if(_next==-1)
		{
			printf("%05ld %ld %ld\n", _id, _data, _next);
		}
		else
		{
			printf("%05ld %ld %05ld\n", _id, _data, _next);
		}
	}
};
int main()
{
	freopen( "sample.in", "r", stdin);
	long root, N, K;
	cin>>root>> N>>K;

	long i;
	map< long, node> maps;
	for( i=0; i<N; ++i)
	{
		long id, data, next;
		cin>>id>>data>>next;
		//scanf("%d %d %d", id, data, next);
		maps[id] = node( id, data, next);
	}

	vector< long> arrs;
	long cur0 = root;
	while( cur0 != -1)
	{
		arrs.push_back( cur0);
		cur0 = maps[cur0]._next;
	}

	int start = 0;
	while( start+K<=arrs.size()){
		reverse( arrs.begin()+start, arrs.begin()+start+K);
		start += K;
	}
	for( i=0; i<arrs.size()-1; ++i)
	{
		maps[arrs[i]]._next = arrs[i+1]; 
	}
	maps[arrs[i]]._next = -1;
	//output
	long cur = arrs[0];
	while( cur != -1)
	{
		maps[cur].output();
		cur = maps[cur]._next;
	}
	return 0;
}