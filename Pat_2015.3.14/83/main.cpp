#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class student
{
public:
	string _name;
	string _id;
	int _grade;
	student( string name, string id, int grade)
	{
		_name = name;
		_id = id;
		_grade = grade;
	}
	friend bool operator < (const student& s1, const student &s2)
	{
		return s1._grade > s2._grade;
	}
	void output()
	{
		printf("%s %s\n", _name.c_str(), _id.c_str());
		//cout<<_name<<_id<<_grade<<endl;
	}
};
int main()
{
	int N;
	freopen( "sample.in", "r", stdin);
	cin>>N;
	vector<student> arrs;
	for( int i=0; i<N; ++i)
	{
		string name, id;
		int grade;
		cin>>name>>id>>grade;
		arrs.push_back( student( name, id, grade));
	}
	int limit0, limit1;
	cin>>limit0>>limit1;
	sort( arrs.begin(), arrs.end());
	bool found = 0;
	for( int i=0; i<arrs.size(); ++i)
	{
		if( arrs[i]._grade >= limit0 && arrs[i]._grade <= limit1)
		{
			found = 1;
			arrs[i].output();
		}
	}
	if(!found)
	{
		cout<<"NONE"<<endl;
	}
	return 0;
}
