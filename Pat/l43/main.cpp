#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class node
{
public:
	int _id;
	node* _left;
	node* _right;

	node(int id):_id(id),_left(NULL), _right(NULL)
	{
	}
};

int tmp_compare = 0;
bool first_bigger(int a)
{
	return a>=tmp_compare;
}

bool first_less(int a)
{
	return a<tmp_compare;
}

vector<int> output;
void output_poster_order(node* root)
{
	if(!root)
		return;
	if(root->_left)
		output_poster_order(root->_left);
	if(root->_right)
		output_poster_order(root->_right);

	output.push_back(root->_id);


}
bool flag = 1;
bool build(vector<int> & arrs, node*& cur_root)
{
	//when the arrs only has 1,2 nodes
	if(arrs.size() == 0)
		return 1;
	cur_root = new node(arrs[0]);
	if(arrs.size() == 1)
		return 1;

	//when nodes>=3
	tmp_compare = arrs[0];
	vector<int>::iterator it;
	if (flag)
	{
		it = find_if(arrs.begin()+1, arrs.end(), first_bigger);
	}
	else
	{
		it = find_if(arrs.begin()+1, arrs.end(), first_less);
	}
	vector<int> arrs_less(arrs.begin()+1, it);
	vector<int> arrs_greater(it, arrs.end());

	//test whether all arr_greater > arrs[0]
	if (flag)
	{
		if(find_if_not(arrs_greater.begin(), arrs_greater.end(), first_bigger) != arrs_greater.end())
			return 0;//not success to build the search tree
	}
	else
	{
		if(find_if_not(arrs_greater.begin(), arrs_greater.end(), first_less) != arrs_greater.end())
			return 0;//not success to build the search tree
	}
	if(!build(arrs_less, cur_root->_left) || !build(arrs_greater, cur_root->_right))
		return 0;

	return 1;

}

int main()
{
	//freopen("sample.in","r", stdin);

	int N;

	cin>>N;
	vector<int> arrs;
 	for(int i=0; i<N; i++)
	{
		int tmp;
		cin>>tmp;
		arrs.push_back(tmp);
	}

	node *root = NULL;
	node *root2 = NULL;
	if(build(arrs, root))
	{
		cout<<"YES"<<endl;
		output_poster_order(root);
		if(output.size()!=0)
		{
			cout<<output[0];
			for(int i=1; i<output.size(); i++)
			{
				cout<<" "<<output[i];
			}
		}
		cout<<endl;
	}
	else 
	{
		flag = 0;
		if(build(arrs, root2))
		{
			cout<<"YES"<<endl;
			output_poster_order(root2);
			if(output.size()!=0)
			{
				cout<<output[0];
				for(int i=1; i<output.size(); i++)
				{
					cout<<" "<<output[i];
				}
			}
			cout<<endl;
		}
		else
			cout<<"NO"<<endl;
	}
	return 0;
}