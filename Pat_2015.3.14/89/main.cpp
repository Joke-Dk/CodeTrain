#include <iostream>
#include <vector>

using namespace std;

bool isEqual( vector<int> & a, vector<int> & b)
{
	for( int i=0; i<a.size(); ++i)
	{
		if(a[i]!=b[i])
		{
			return 0;	
		}
	}	
	return 1;
}

void Merge( vector<int>& process, int begin, int mid, int end)
{
	vector<int> tmp;
	int index[2];
	index[0]=begin;
	index[1]=mid;
	int limits[2];
	limits[0]=mid;
	limits[1]=end+1;	
	int tag=0;
	while( index[0]<limits[0]&&index[1]<limits[1])
	{
		tag = process[index[0]]<process[index[1]]?0:1;
		tmp.push_back( process[index[tag]]);
		index[tag]++;
	}
	tmp.insert( tmp.end(), process.begin()+index[1-tag], process.begin()+limits[1-tag]);
	for( int i=0; i<tmp.size(); ++i)
	{
		process[ begin+i] = tmp[i];
	}

}

int main()
{
	freopen("sample.in", "r", stdin);
	int N;
	cin>>N;
	vector<int> arrs0(N), arrs1(N);

	for(int i=0; i<N; ++i)
	{
		cin>>arrs0[i];
	}
	for(int i=0; i<N; ++i)
	{
		cin>>arrs1[i];
	}

	bool flag=0;
	//Insert Sort
	vector<int > process = arrs0;
	for( int i=0; i<N; ++i)
	{
		for( int j=0; j<i; ++j)
		{
			if( process[j]>process[i])
			{
				int tmp = process[i];
				for( int k=i; k>j; k--)
				{
					process[k] = process[k-1];
				}
				process[j] = tmp;
				break;
			}
		}
		if(flag)
		{
			cout<<"Insertion Sort"<<endl;
			cout<<process[0];
			for( int j=1; j<N; ++j){ cout<<" "<<process[j];}
			cout<<endl;
			break;
		}

		if( isEqual( process, arrs1))
		{
			flag=1;
		}
	}

	flag=0;
	//
	vector<int > process2 = arrs0;
	int step = 2;
	while( step/2<N)
	{
		int start = 0;
		while(start<N)
		{
			int mid = start+step/2; 
			if( mid<N)
			{
				// sort
				int end = min(start+step-1, N-1);
				Merge( process2, start, mid, end);
			}
			start+=step;
		}

		if(flag)
		{
			cout<<"Merge Sort"<<endl;
			cout<<process2[0];
			for( int j=1; j<N; ++j){ cout<<" "<<process2[j];}
			cout<<endl;
			break;
		}

		if( isEqual( process2, arrs1))
		{
			flag=1;
		}
		step*=2;
	}

	return 0;
}
