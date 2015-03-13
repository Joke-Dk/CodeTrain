#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <vector>
using namespace std;

class node
{
public:
	int _id;
	node * _left;
	node * _right;
	node()
	{
		_id = -1;
		_left = NULL;
		_right = NULL;
	}
};

int min( int a, int b)
{
	return a<b?a:b;
}
void cut( node * _node, int id0, int id1)
{
	int size = id1-id0+1;
	if( size==1)
	{
		_node->_id = id0;
		//cout<<_node->_id<<endl;
		return;
	}

	int exp = log(double(size+1))/log(double(2))-1;
	int remain = size - pow( 2, exp+1)+1;
	int size1 = pow(2, exp)-1 + min( remain, pow(2, exp));
	node *left = new node();
	_node->_id = id0+size1;
	_node->_left = left;
	//cout<<_node->_id<<endl;
	cut( left, id0, id0+size1-1);

	if( id0+size1+1<=id1)
	{
		node *right = new node();
		_node->_right = right;
		cut( right, id0+size1+1, id1);
	}
}

vector< int> arrs;
void travel( node* _node)
{
	queue< node*> queues;

	queues.push( _node);
	while( !queues.empty())
	{
		node* cur = queues.front();
		//cout<<cur->_id<<endl;
		arrs.push_back(cur->_id);
		queues.pop();
		if( cur->_left)
		{
			queues.push( cur->_left);
		}
		if( cur->_right)
		{
			queues.push( cur->_right);
		}
	}
}
int main()
{
	freopen( "sample.in", "r", stdin);
	int N;
	cin>>N;
	int i;
	vector<int> seq(N);
	for( i=0; i<N; ++i)
	{
		cin>>seq[i];
	}
	sort( seq.begin(), seq.end());
	node *root = new node();
	cut( root, 0, N-1);
	travel(root);
	for( i=0; i<arrs.size(); ++i)
	{
		if( i!=0)
		{
			cout<<" ";
		}
		cout<<seq[ arrs[i]];
	}
	cout<<endl;
	return 0;
}