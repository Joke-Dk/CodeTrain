#include <iostream>
#include <vector>
#include <string>
using namespace std;


int BFMatch( string& s, string& p)
{
	int i, j;
	i=0;
	while( i<s.length())
	{
		j=0;
		while( s[i]==p[j] && j<p.length())
		{
			i++;
			j++;
		}
		if (j==p.length())
		{
			return i-j;
		}
		i = i-j+1;
	}
	return -1;
}

int KMPMatch( string& s, string &p, vector<int>& next)
{
	int i, j;
	i=0;
	j=0;
	while(i<s.length())
	{
		while( s[i]==p[j] && j<p.length())
		{
			i++;
			j++;
		}
		if( j==p.length())
		{
			return i-j;
		}
		//else: different for pos-j
		if( j==0||j-1==0)
		{
			i=i-j+1;
		}
		else
		{
			j=next[j-1];
		}
		
	}
	return -1;
}

vector<int> getNextArray( string& s)
{
	vector<int> next;
	next.resize( s.length());
	next[0] = -1;
	for(int i=1; i<s.length(); i++)
	{	
		int j;
		for( j=i; j>0; j--)
		{
			string tmpStr1 = s.substr( 0, j);
			string tmpStr2 = s.substr( i-j+1, j);
			if( tmpStr1==tmpStr2)
				break;	
		}
		next[i] = j;
	}	
	return next;
}
int main()
{
	string s = "ababcababa";
	string p = "ababa";
	
	string p2 = "ABCDABD";
	//int ret = BFMatch( s, p);
	vector<int>& next = getNextArray( p2);
	//for(int i=0; i<next.size(); i++){
	//	cout<<next[i]<<endl;
	//}
	int ret = KMPMatch(s, p, next);
	cout<<ret<<endl;
	

	return 0;
}