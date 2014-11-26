#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

vector<vector<int>> tmpArr;
vector<string> ret;
void output( int index, string& s, vector<string>& record)
{
	if (index==0)
	{
		//for(int i=0; i<record.size(); i++)
		//{
		//	cout<<record[record.size()-1-i]<<" ";
		//}
		//cout<<endl;
		string getStr = "";
		for( int i=0; i<record.size(); i++)
		{
			getStr += record[record.size()-1-i];
			if(i!=record.size()-1)
			{
				getStr += " ";
			}
		}
		cout<<getStr<<endl;
		ret.push_back( getStr);
		return;
	}
	for( int i=0; i<tmpArr[index].size(); ++i)
	{
		int tmpLen = tmpArr[index][i];
		if( tmpLen<0)
		{
			return;
		}
		int tmpIndex = index - tmpLen;
		string tmpStr = s.substr(tmpIndex, tmpLen);
		record.push_back( tmpStr);
		output( tmpIndex, s, record);
		record.pop_back();
	}
}

vector<string> wordBreak( string s, set<string> &dict)
{
	vector<int> tmpA;
	tmpA.push_back(-1);
	tmpArr.resize( s.length()+1, tmpA);
	tmpArr[0][0] = 0;
	for(int i=1; i<s.length()+1; ++i)
	{
		for( int j=0; j<i; ++j)
		{
			if( tmpArr[j][0]>-1 && dict.find( s.substr(j, i-j))!=dict.end())
			{
				if(tmpArr[i][0]==-1){
					tmpArr[i][0] = i-j;
				}
				else
				{
					tmpArr[i].push_back(i-j);
				}
				//break;
			}
		}
	}
	
	//for dispaly
	for(int i=0; i<s.length()+1; i++)
	{
		cout<<"size: "<<tmpArr[i].size()<<" ";
		for( int j=0; j<tmpArr[i].size(); j++)
		{
			cout<<tmpArr[i][j]<<" ";
		}
		cout<<endl;
			
	}
	//output the standard format of word-array result 
	//recursive-cout
	vector<string> tmpArrStr;
	output( s.length(), s, tmpArrStr);
	
	return ret;
}

int main()
{
	//freopen( "sample.in", "r", stdin);
	#if 1
		string s = "catsanddog";
		set<string> dict;
		dict.insert( "cat");
		dict.insert( "cats");
		dict.insert( "and");
		dict.insert( "sand");
		dict.insert( "dog");
	#else
		string s = "a";
		set<string> dict;
		dict.insert( "a");
	#endif	
	wordBreak( s, dict);
	return 0;
}