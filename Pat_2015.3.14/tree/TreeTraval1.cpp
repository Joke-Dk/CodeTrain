#include<iostream>
#include<stack> //STL
#include<queue>
using namespace std;
class Tree
{
public:
	Tree *Left;
	Tree *Right;
	char data;
	Tree();

	//成员函数
	void CreateTree(Tree* &node);
	//递归的遍历二叉树
	void PreOrderVisit(Tree *T);
	void InOrderVisit(Tree *T);
	void LastOrderVisit(Tree *T);
	void LevelOrderVisit(Tree *T);
	//非递归的调用二叉树
	void NoPreRecursiveVist(Tree *T);
	void NoInRecursiveVist(Tree *T);
	void NoLastRecursiveVist(Tree *T);
};

Tree::Tree()
{
}
//构造树
void Tree::CreateTree(Tree* &node)
{
	char temp;
	cout<<"输入改节点的数据"<<endl;
	cin>>temp;
	if(temp=='c')
	{
		node=NULL;
	}
	else
	{
		node=new Tree;
		node->data=temp;
		CreateTree(node->Left);
		CreateTree(node->Right);
	}
}
//先序遍历树
void Tree::PreOrderVisit(Tree *T)
{

	if(T)
	{
		cout<<T->data<<'/t';
		PreOrderVisit(T->Left);
		PreOrderVisit(T->Right);
	}
}
//中序遍历树
void Tree::InOrderVisit(Tree *T)
{

	if(T)
	{
		InOrderVisit(T->Left);
		cout<<T->data<<'/t';
		InOrderVisit(T->Right);
	}
}
//后序遍历树
void Tree::LastOrderVisit(Tree *T)
{

	if(T)
	{
		LastOrderVisit(T->Left);
		LastOrderVisit(T->Right);
		cout<<T->data<<'/t';
	}

}
//层序遍历
void Tree::LevelOrderVisit(Tree *T)
{
	queue<Tree *>Q;
	if(!T)
		return;
	Q.push(T);
	Tree *temp=NULL;
	while(!Q.empty())
	{
		temp=Q.front();
		cout<<temp->data<<'/t';
		Q.pop();
		if(temp->Left)
			Q.push(temp->Left);
		if(temp->Right)
			Q.push(temp->Right);
	}
}
//非递归的遍历树的三种方法
void Tree::NoInRecursiveVist(Tree *T)
{
	stack<Tree *>S; //用来保存的节点的栈
	Tree *p;
	p=T;
	while(!S.empty()||p)
	{
		if(p) //p非空
		{
			S.push(p);
			p=p->Left;
		}
		else
		{
			p=S.top();
			S.pop();
			cout<<p->data<<'/t';
			p=p->Right;
		}
	}
}

void Tree::NoPreRecursiveVist(Tree *T)
{
	stack<Tree *>S; //用来保存的节点的栈
	Tree *p;
	p=T;
	while(!S.empty()||p)
	{
		if(p) //p非空
		{
			S.push(p);
			cout<<p->data<<'/t';
			p=p->Left;
		}
		else
		{
			p=S.top();
			S.pop();
			p=p->Right;
		}
	}
}
void Tree::NoLastRecursiveVist(Tree *T)
{
	stack<Tree *>S;
	Tree *p;
	Tree *pre=NULL;
	p=T;
	while(!S.empty()||p)
	{
		while(p)
		{
			S.push(p);
			p=p->Left;
		}
		p=S.top();
		if(p->Right==NULL||p->Right==pre)
		{
			cout<<p->data<<'/t';
			pre=p;
			p=NULL;
			S.pop();
		}
		else
			p=p->Right;
	}
}
void main()
{
	Tree *T=NULL;
	T->CreateTree(T);
	cout<<"先序遍历"<<endl;
	T->PreOrderVisit(T);
	cout<<endl;
	cout<<"中序遍历"<<endl;
	T->InOrderVisit(T);
	cout<<endl;
	cout<<"后序遍历"<<endl;
	T->LastOrderVisit(T);
	cout<<endl;
	cout<<"层序遍历"<<endl;
	T->LevelOrderVisit(T);
	cout<<endl;
	cout<<"非递归先序遍历二叉树"<<endl;
	T->NoPreRecursiveVist(T);
	cout<<endl;
	cout<<"非递归中序遍历二叉树"<<endl;
	T->NoInRecursiveVist(T);
	cout<<endl;
	cout<<"非递归后序遍历二叉树"<<endl;
	T->NoLastRecursiveVist(T);
	cout<<endl;
	system("pause");
}