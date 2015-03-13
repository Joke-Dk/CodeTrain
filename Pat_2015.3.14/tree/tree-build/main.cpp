#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class node
{
public:
	char _id;
	node *  _left;
	node * _right; 
};

vector< char> preOrder;
vector< char> inOrder;

node* buildTree( int pre, int mid, int n)
{
	if( n==0)
	{
		return NULL;
	}
	node *newone = new node();
	newone->_id = preOrder[pre];
	cout<<newone->_id<<endl;
	int midIndex = find( inOrder.begin(), inOrder.end(), preOrder[pre])-inOrder.begin();
	int lenL = midIndex-mid;
	int lenR = n - lenL -1;
	newone->_left = buildTree( pre+1, mid, lenL);
	newone->_right = buildTree( pre+1+lenL, mid+lenL+1, lenR);
	return newone;
}

void lastpreOutput( node* cur)
{
	if( cur)
	{
		cout<<"pre: "<<cur->_id<<endl;
		lastpreOutput( cur->_left);
		lastpreOutput( cur->_right);

	}
}

int main()
{
	freopen( "sample.in", "r", stdin);
	int N, i;
	cin>>N;

	preOrder.resize(N);
	inOrder.resize(N);
	
	for( i =0; i<N; ++i)
	{
		cin>>preOrder[i];
	}
	for( i=0; i<N; ++i)
	{
		cin>>inOrder[i];
	}
	node* root = buildTree( 0, 0, N);
	lastpreOutput(root);
	return 0;
}