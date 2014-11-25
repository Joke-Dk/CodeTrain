#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class student
{
public:
	string _name;
	string _id;
	int _grade;
	
	student(string name ,string id, int grade)
	{
		_name = name;
		_id = id;
		_grade = grade;
	}
};

bool cmp(student* s1, student *s2)
{
	return s1->_grade < s2->_grade;
}

int main()
{
	//freopen("sample.in", "r", stdin);

	int N;
	cin>>N;
	vector<student *> arrs_M;
	vector<student *> arrs_F;
	for(int i=0; i<N; i++)
	{
		string name, gender, id;
		int grade;
		cin>>name>>gender>>id>>grade;

		if(gender[0]=='M')
		{
			arrs_M.push_back(new student(name, id, grade));
		}
		else
			arrs_F.push_back(new student(name, id, grade));
	}

	student * low_M = NULL;
	student * high_F = NULL;
	if(arrs_F.size()!=0)
	{
		high_F = *max_element(arrs_F.begin(), arrs_F.end(), cmp);
		cout<<high_F->_name<<" "<<high_F->_id<<endl;
	}
	else
	{
		cout<<"Absent"<<endl;
	}
	if(arrs_M.size()!=0)
	{
		low_M = *min_element(arrs_M.begin(), arrs_M.end(), cmp);
		cout<<low_M->_name<<" "<<low_M->_id<<endl;
	}
	else
	{
		cout<<"Absent"<<endl;
	}

	if(arrs_F.size()!=0 && arrs_M.size()!=0)
	{
		cout<<high_F->_grade-low_M->_grade<<endl;
	}
	else
	{
		cout<<"NA"<<endl;
	}
	return 0;
}