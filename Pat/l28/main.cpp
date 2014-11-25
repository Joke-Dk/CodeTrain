#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class record
{
public:
	string _id;
	string _name;
	int _score;
	record(string id, string name, int score)
	{
		_id = id;
		_name = name;
		_score = score;
	}

	friend ostream & operator<<(ostream &os, record tmp)
	{
		os<<tmp._id<<" "<<tmp._name<<" "<<tmp._score<<endl;
		return os;
	}
};

bool cmp1(record* r1, record* r2)
{
	return r1->_id<r2->_id;
}
bool cmp2(record* r1, record* r2)
{
	if (r1->_name==r2->_name)
		return cmp1(r1, r2);
	return r1->_name<r2->_name;
}
bool cmp3(record* r1, record* r2)
{
	if (r1->_score==r2->_score)
		return cmp1(r1, r2);
	return r1->_score<r2->_score;
}
int main()
{
	//freopen("sample.in", "r", stdin);

	int N, C;
	cin>>N>>C;
	vector<record*>  arrs;
	for(int i=0; i<N; i++)
	{
		string id, name;
		int score;
		
		cin>>id>>name>>score;
		arrs.push_back(new record(id, name, score));
	}
	if(C==1)
		sort(arrs.begin(), arrs.end(), cmp1);
	else if(C==2)
		sort(arrs.begin(), arrs.end(), cmp2);
	else
		sort(arrs.begin(), arrs.end(), cmp3);
	for(int i= 0; i<arrs.size(); i++)
	{
		cout<<*arrs[i];
	}

	return 0;
}