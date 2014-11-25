#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


class node
{
public:
	int id;
	node* left;
	node* right;
	node()
	{
		left = NULL;
		right = NULL;
	}
};

void rebuid(vector<int> postorder, vector<int> inorder, node*& root)
{
	if(root==NULL)
		root = new node();
	//find root
	root->id = *(postorder.end()-1);

	vector<int>::iterator it = find(inorder.begin(), inorder.end(), root->id);
	
	if(inorder.begin()!=it)
	{
		vector<int> arr_left_inorder(inorder.begin(), it);
		//vector<int>::iterator it0 = find(postorder.begin(), postorder.end(), *(it-1));
		vector<int> arr_left_postor(postorder.begin(), postorder.begin()+arr_left_inorder.size());
		//node* node0 = new node();
		rebuid( arr_left_postor, arr_left_inorder, root->left);
	}
	if(inorder.end()-1!=it)
	{
		vector<int> arr_right_inorder(it+1, inorder.end());
		//vector<int>::iterator it0 = find(postorder.begin(), postorder.end(), *(it+1));
		vector<int> arr_right_postor(postorder.end()-1-arr_right_inorder.size(), postorder.end()-1);
		rebuid( arr_right_postor, arr_right_inorder, root->right);
	}

	
}

void output(node * root, int N)
{
	queue<node*> q0;
	if(root)
		q0.push(root);
	int i=0;
	while(!q0.empty())
	{
		node* tmp = q0.front();
		q0.pop();
		i++;
		if (i==N)
		{
			cout<<tmp->id;
			break;
		}
		cout<<tmp->id<<" ";
		if(tmp->left)
			q0.push(tmp->left);
		if(tmp->right)
			q0.push(tmp->right);

	}
}

int main()
{
	//freopen("sample.in","r", stdin);
	
	int N;
	cin>>N;
	vector<int> postorder;
	vector<int> inorder;

	for(int i=0; i<N; i++)
	{
		int temp;
		cin>>temp;
		postorder.push_back(temp);
	}
	for(int i=0; i<N; i++)
	{
		int temp;
		cin>>temp;
		inorder.push_back(temp);
	}

	node *root = NULL;// = new node();
	rebuid(postorder, inorder, root);


	output(root, N);
	return 0;
}