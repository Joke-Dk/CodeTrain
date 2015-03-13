// BinaryTree.cpp : �������̨Ӧ�ó������ڵ㡣
//C++ʵ����ʽ�����������÷ǵݹ�ķ�ʽ�������򣬺������������
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
		cout<<"��������ڵ�:"<<endl;
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

//��������
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
//����������
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
	    cout<<"��������"<<endl;
	    Create(bt->lchild );
	    cout<<"�����Һ���"<<endl;
	    Create(bt->rchild );
    }
}
/************************************************************************
����������������ǵݹ���ʽ��
˼�룺�����ߵ���ͷ����ջ����ջ�����ʽڵ㣬����һ��
************************************************************************/
template <class T>
void BiTree<T>::InOrderTraverse()
{
	stack<BiNode<T>*> sta; //����һ�����BiNode��ָ��Ŀ�ջ
	BiNode<T>* p = root;
	sta.push(p);   //����ָ����ջ
	while(!sta.empty())
	{
		while (NULL != p)
		{//�����ߵ���ͷ���������������Ľڵ�ָ�룬��ջ
			p = p->lchild; 
			if (NULL != p)
			{
				sta.push(p);
			}
		}

		if (!sta.empty())
		{
			p = sta.top();  
			cout << p->data << " ";  //����ջ��Ԫ�أ�
			sta.pop();     //ջ��Ԫ�س�ջ
			p = p->rchild;  //����һ��	
			if (NULL != p)
			{
				sta.push(p);
			}
		}		
	}
}
/************************************************************************
����������������ǵݹ���ʽ��
˼�룺�����ߵ���ͷ����ջ�����ʽڵ㡣��ջ������һ��
************************************************************************/
template<class T>
void BiTree<T>::PreOrderTraverse()
{
	stack<BiNode<T>*> sta;
	BiNode<T>* p = root;
	sta.push(p);   //����ָ����ջ
	while(!sta.empty())
	{
		while (NULL != p)
		{//�����ߵ���ͷ���������������Ľڵ�ָ�룬��ջ
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
			sta.pop();     //ջ��Ԫ�س�ջ
			p = p->rchild;  //����һ��	
			if (NULL != p)
			{
				sta.push(p);
			}
		}		
	}
}

/************************************************************************
 ����������ǵݹ���ʽ��                                               
 ˼�룺�Ӹ��ڵ㿪ʼ�������ߵ���ͷ������ջ��ͬʱ���ñ�־λΪ1.
 ��ջʱ�������ڵ��������������ж��ǵڼ��η��ʣ�����ǵ�1�η��ʣ�
 �򲻳�ջ������־λ��Ϊ2������ǵڶ��η��ʣ����ջ��
                                               
************************************************************************/
template<class T>
void BiTree<T>::PostOrderTraverse()
{
	stack<BiNode<T>*> sta; //��Žڵ�ָ���ջ
	stack<int> flagsta;  //��ű�־λ��ջ��ÿ�����룩һ���ڵ�ָ�룬ͬ�������룩һ����־λ
	unsigned flag;  //���ñ�־λ��1-��һ�η��ʣ�2-�ڶ��η���
	BiNode<T>* p = root;
	sta.push(p);   //����ָ����ջ
	flagsta.push(1);
	while(!sta.empty())
	{
		while (NULL != p && NULL != p->lchild)
		{//�����ߵ���ͷ���������������Ľڵ�ָ�룬��ջ
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
			{//������������գ����ǵ�һ�η���
				flagsta.push(2);	  //��һ�η���ʱԪ�ز���ջ��������־λ����Ϊ2	
				p = p->rchild;    //����һ��
				sta.push(p);
				flagsta.push(1);
			}
			else
			{
				sta.pop(); //Ԫ�س�ջ
				cout << p->data << " ";  //����ջ��Ԫ��
				p = NULL; //��ָ����Ϊ��
			}		
		}		
	}
}