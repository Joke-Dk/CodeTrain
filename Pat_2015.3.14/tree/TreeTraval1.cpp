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

	//��Ա����
	void CreateTree(Tree* &node);
	//�ݹ�ı���������
	void PreOrderVisit(Tree *T);
	void InOrderVisit(Tree *T);
	void LastOrderVisit(Tree *T);
	void LevelOrderVisit(Tree *T);
	//�ǵݹ�ĵ��ö�����
	void NoPreRecursiveVist(Tree *T);
	void NoInRecursiveVist(Tree *T);
	void NoLastRecursiveVist(Tree *T);
};

Tree::Tree()
{
}
//������
void Tree::CreateTree(Tree* &node)
{
	char temp;
	cout<<"����Ľڵ������"<<endl;
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
//���������
void Tree::PreOrderVisit(Tree *T)
{

	if(T)
	{
		cout<<T->data<<'/t';
		PreOrderVisit(T->Left);
		PreOrderVisit(T->Right);
	}
}
//���������
void Tree::InOrderVisit(Tree *T)
{

	if(T)
	{
		InOrderVisit(T->Left);
		cout<<T->data<<'/t';
		InOrderVisit(T->Right);
	}
}
//���������
void Tree::LastOrderVisit(Tree *T)
{

	if(T)
	{
		LastOrderVisit(T->Left);
		LastOrderVisit(T->Right);
		cout<<T->data<<'/t';
	}

}
//�������
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
//�ǵݹ�ı����������ַ���
void Tree::NoInRecursiveVist(Tree *T)
{
	stack<Tree *>S; //��������Ľڵ��ջ
	Tree *p;
	p=T;
	while(!S.empty()||p)
	{
		if(p) //p�ǿ�
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
	stack<Tree *>S; //��������Ľڵ��ջ
	Tree *p;
	p=T;
	while(!S.empty()||p)
	{
		if(p) //p�ǿ�
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
	cout<<"�������"<<endl;
	T->PreOrderVisit(T);
	cout<<endl;
	cout<<"�������"<<endl;
	T->InOrderVisit(T);
	cout<<endl;
	cout<<"�������"<<endl;
	T->LastOrderVisit(T);
	cout<<endl;
	cout<<"�������"<<endl;
	T->LevelOrderVisit(T);
	cout<<endl;
	cout<<"�ǵݹ��������������"<<endl;
	T->NoPreRecursiveVist(T);
	cout<<endl;
	cout<<"�ǵݹ��������������"<<endl;
	T->NoInRecursiveVist(T);
	cout<<endl;
	cout<<"�ǵݹ�������������"<<endl;
	T->NoLastRecursiveVist(T);
	cout<<endl;
	system("pause");
}