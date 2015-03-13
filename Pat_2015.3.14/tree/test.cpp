#include <iostream>

using namespace std;

class node
{
	
};

void preOrder( node* root)
{
	stack< int> S;
	node *p = root;
	while( !S.empty || p)
	{
		if(p)
		{
			cout<<p->left<<endl;
			S.push( p);
			p = p->left;
		}
		else
		{
			p = p.top();
			p.pop();
			p = p->right;
		}
	}
}