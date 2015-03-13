#include <iostream>
#include <stack>
using namespace std;

class node
{
public:
	int _id;
	node *_left;
	node *_right;
};

void create( node* &root)
{
	int id;
	cin>>id;
	if( id<0)
	{
		root = NULL;
	}
	else
	{
		root = new node();
		root->_id = id;
		create( root->_left);
		create( root->_right);
	}

}

void inorder( node *root)
{
	node* p = root;
	stack<node* > stacks;
	while(!stacks.empty()||p)
	{
		if( p)
		{
			stacks.push(p);
			p = p->_left;
		}
		else
		{
			p = stacks.top();
			stacks.pop();
			cout<<p->_id<<endl;
			p = p->_right;
		}
	}
}

void preorder( node * root)
{
	node * p = root;
	stack< node*> S;
	while( !S.empty() || p)
	{
		if(p)
		{
			cout<<p->_id<<endl;
			S.push(p);
			p = p->_left;
		}
		else
		{
			p = S.top();
			S.pop();
			p = p->_right;
		}
	}
}

void lastorder( node * root)
{
	node *p = root;
	stack<node*> S;
	node* pre = NULL;
	while(!S.empty()||p)
	{
		if(p)
		{
			S.push(p);
			p=p->_left;
		}
		else
		{
			p = S.top();
			if( p->_right!=NULL && p->_right!=pre)
			{
				p = p->_right;
			}
			else
			{
				cout<<p->_id<<endl;
				pre = p;
				p =NULL;
				S.pop();
			}
		}
	}
}

int main()
{
	freopen( "sample.in", "r", stdin);
	node *root = NULL;
	create( root);
	lastorder(root);
	return 0;
}