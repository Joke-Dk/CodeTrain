// BinaryTree.cpp : 定义控制台应用程序的入口点。
//C++实现链式二叉树，采用非递归的方式先序，中序，后序遍历二叉树
#include "stdafx.h"
#include<iostream>
#include<string>
#include <stack>

using namespace std;

template<class T>
struct BiNode
{
	T data;
	struct BiNode<T> *rchild,*lchild;
};

template<class T>
class BiTree
{
public:
	BiTree(){
		cout<<"请输入根节点:"<<endl;
		Create(root);
		if (NULL != root)
		{
			cout<<"root="<<root->data<<endl;
		}
		else
		{
			cout << "The BinaryTree is empty." << endl;
		}
	}
	~BiTree(){Release(root);}
	void InOrderTraverse();
	void PreOrderTraverse();
	void PostOrderTraverse();

private:
	BiNode<T> *root;
	void Create(BiNode<T>* &bt);
	void Release(BiNode<T> *bt);
};

//析构函数
template <class T>
void BiTree<T>::Release(BiNode<T> *bt) 
{
	
	if(bt==NULL)
	{
		Release(bt->lchild );
		Release(bt->rchild );
		delete bt;
	}
}
//建立二叉树
template <class T>
void BiTree<T>::Create(BiNode<T>* &bt) 
{
	T ch;
    cin>>ch;
    if(ch== 0)bt=NULL;
    else
    {
	    bt=new BiNode<T>;
	    bt->data =ch;
	    cout<<"调用左孩子"<<endl;
	    Create(bt->lchild );
	    cout<<"调用右孩子"<<endl;
	    Create(bt->rchild );
    }
}
/************************************************************************
方法：中序遍历（非递归形式）
思想：向左走到尽头，入栈。出栈，访问节点，向右一步
************************************************************************/
template <class T>
void BiTree<T>::InOrderTraverse()
{
	stack<BiNode<T>*> sta; //定义一个存放BiNode型指针的空栈
	BiNode<T>* p = root;
	sta.push(p);   //将根指针入栈
	while(!sta.empty())
	{
		while (NULL != p)
		{//向左走到尽头，并保留所经过的节点指针，入栈
			p = p->lchild; 
			if (NULL != p)
			{
				sta.push(p);
			}
		}

		if (!sta.empty())
		{
			p = sta.top();  
			cout << p->data << " ";  //访问栈顶元素，
			sta.pop();     //栈顶元素出栈
			p = p->rchild;  //向右一步	
			if (NULL != p)
			{
				sta.push(p);
			}
		}		
	}
}
/************************************************************************
方法：先序遍历（非递归形式）
思想：向左走到尽头，入栈，访问节点。出栈，向右一步
************************************************************************/
template<class T>
void BiTree<T>::PreOrderTraverse()
{
	stack<BiNode<T>*> sta;
	BiNode<T>* p = root;
	sta.push(p);   //将根指针入栈
	while(!sta.empty())
	{
		while (NULL != p)
		{//向左走到尽头，并保留所经过的节点指针，入栈
			cout << p->data << " ";
			p = p->lchild; 
			if (NULL != p)
			{
				sta.push(p);
			}	
		}

		if (!sta.empty())
		{
			p = sta.top();  
			sta.pop();     //栈顶元素出栈
			p = p->rchild;  //向右一步	
			if (NULL != p)
			{
				sta.push(p);
			}
		}		
	}
}

/************************************************************************
 后序遍历（非递归形式）                                               
 思想：从根节点开始，向左走到尽头，并入栈，同时设置标志位为1.
 出栈时如果这个节点有右子树，则判断是第几次访问，如果是第1次访问，
 则不出栈，将标志位改为2；如果是第二次访问，则出栈。
                                               
************************************************************************/
template<class T>
void BiTree<T>::PostOrderTraverse()
{
	stack<BiNode<T>*> sta; //存放节点指针的栈
	stack<int> flagsta;  //存放标志位的栈，每出（入）一个节点指针，同步出（入）一个标志位
	unsigned flag;  //设置标志位，1-第一次访问，2-第二次访问
	BiNode<T>* p = root;
	sta.push(p);   //将根指针入栈
	flagsta.push(1);
	while(!sta.empty())
	{
		while (NULL != p && NULL != p->lchild)
		{//向左走到尽头，并保留所经过的节点指针，入栈
			p = p->lchild; 
			sta.push(p);
			flagsta.push(1);
		}

		if (!sta.empty())
		{
			flag = flagsta.top();
			flagsta.pop();
			p = sta.top();

			if ((NULL != p->rchild) && flag == 1 )
			{//如果右子树不空，且是第一次访问
				flagsta.push(2);	  //第一次访问时元素不出栈，但将标志位设置为2	
				p = p->rchild;    //向右一步
				sta.push(p);
				flagsta.push(1);
			}
			else
			{
				sta.pop(); //元素出栈
				cout << p->data << " ";  //访问栈顶元素
				p = NULL; //将指针置为空
			}		
		}		
	}
}