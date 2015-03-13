#include <iostream>
#include <set>
#include <stack>
#include <string>

using namespace std;

class mystack
{
public:
	int median;
	multiset< int, greater<int> > down;
	multiset< int, less<int> > up;
	stack< int> stk;

	mystack(){ median = -1;}
	void push( int id)
	{
		stk.push( id);
		if(median==-1)
		{
			median = id;
			return;
		}
		if(id>=median)
		{
			up.insert( id);
		}
		else
		{
			down.insert( id);
		}

		sort();
	}

	void sort()
	{
		if(median == -1)
		{
			if(up.size()==0)
			{
				return;
			}
			if(down.size()<up.size())
			{
				median = * up.begin();
				up.erase( up.begin());
			}
			else
			{
				median = * down.begin();
				down.erase( down.begin());
			}
			return;
		}
		if(down.size()>up.size())
		{
			up.insert( median);
			median = * down.begin();
			down.erase( down.begin());
		}
		else if( down.size()+1 < up.size())
		{
			down.insert(median);
			median = * up.begin();
			up.erase( up.begin());
		}
	}

	void pop()
	{
		if(stk.empty())
		{
			//ut<<"Invalid"<<endl;
			printf( "Invalid\n");
			return;
		}
		else
		{
			int id = stk.top();
			//cout<<id<<endl;
			printf( "%d\n", id );
			stk.pop();
			if( id<median)
			{
				down.erase( id);
			}
			else if( id>median)
			{
				up.erase( id);
			}
			else
			{
				median = -1;
			}
			sort();
		}
	
	}

	void peek()
	{
		if(median==-1)
		{
			//ut<<"Invalid"<<endl;
			printf( "Invalid\n");
		}
		else
		{
			//cout<<median<<endl;
			printf( "%d\n", median );
		}	
	}
};
int main()
{
	char chs[20];
	freopen( "sample.in", "r", stdin);
	int N;
	cin>>N;
	int i;
	getchar();
	mystack S;
	for( i=0; i<N; ++i)
	{
		//string command;
		//getline( cin, command);
		scanf( "%s", chs);
		if( chs[1]=='o')
		{
			S.pop();
		}
		else if( chs[1]=='e')
		{
			S.peek();
		}
		else if( chs[1]=='u')
		{
			int d=0;
			scanf( "%d", &d);
			S.push(d);
		}
	}
	return 0;
}