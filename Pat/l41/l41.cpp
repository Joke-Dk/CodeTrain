#include <iostream>
#include <map>
#include <algorithm>
using namespace std;


int main()
{
	//freopen("sample.in", "r", stdin);
	int n;
	cin>>n;
	
	map< int, pair<bool, int>> map0;
	int tmpI;
	for( int i=0; i<n; ++i)
	{
		cin>>tmpI;
		if( map0.find( tmpI)==map0.end()){
			map0[tmpI] = pair<bool, int>( 1, i);
		}
		else
		{
			map0[tmpI] = pair<bool, int>( 0, i);
		}
	}
	
	int winMin = n+1;
	int winValue = -1;
	for( map< int, pair<bool, int>>::iterator it = map0.begin(); it!= map0.end(); it++){
		if( it->second.first && it->second.second<winMin){
			winMin = it->second.second;
			winValue = it->first;
		}
	}
	if( winValue==-1){
		cout<<"None"<<endl;
	}
	else
	{
		cout<<winValue<<endl;
	}
	

	return 0;
}