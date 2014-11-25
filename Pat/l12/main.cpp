#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
const int MAX = 100000000;
char chs[5] = "ACME";

class student
{
public:
	int _ID;
	int _data[4];
	int _rank[4];
	int max_rank;
	int max_rank_index;
	student(int* data0)
	{
		max_rank = MAX;
		max_rank_index = -1;
		_ID = data0[0];
		_data[0] = 0;
		for(unsigned i=0; i<3; i++)
		{
			_data[i+1] = data0[i+1];
			_data[0] += data0[i+1];
		}
		_data[0] /= 3;
	}
	student(const student& s1)
	{
		_ID = s1._ID;
		//memcpy( _data, s1._data, sizeof(int)*4);
		for (unsigned i=0; i<4; i++)
		{
			_data[i] = s1._data[i];		
		}
	}

	void find_max_rank()
	{
		for (int i=0; i<4; i++)
		{
			if (_rank[i]<max_rank)
			{
				max_rank = _rank[i];
				max_rank_index = i;
			}
		}
	}

	void output_rank()
	{
		cout<<max_rank+1<<" "<<chs[max_rank_index]<<endl;
	}

};

int cmp_index = 0;
bool cmp_stu(student* s1, student* s2)
{
	return s1->_data[cmp_index]>s2->_data[cmp_index];
}

void solve(vector<student*>& arr_student)
{
	//sort for 4 cols
	for(cmp_index = 0; cmp_index<4; cmp_index++)
	{
		sort(arr_student.begin(), arr_student.end(), cmp_stu);
		int pre_val = -1, pre_rank = -1;
		for (unsigned int i=0; i<arr_student.size(); i++)
		{
			int data_tmp = arr_student[i]->_data[cmp_index];
			if (i==0||pre_val != data_tmp)
			{
				arr_student[i]->_rank[cmp_index] = i;
				pre_val = data_tmp;
				pre_rank = i;
				
			}
			else// if(pre_val == arr_student[i]->_data[cmp_index])
			{
				arr_student[i]->_rank[cmp_index] = pre_rank;
			}
			//pre_rank = arr_student[i]->_rank[cmp_index];
			
			
		}
	}

	//find best rank
	for(vector<student* >::iterator it=arr_student.begin(); it != arr_student.end(); it++)
	{
		(*it)->find_max_rank();
	}
}

void output_student_fun(vector<student*>& arr_student, int ID)
{
	for(vector<student* >::iterator it=arr_student.begin(); it != arr_student.end(); it++)
	{
		if((*it)->_ID == ID)
		{
			(*it)->output_rank();
			return;
		}
			
	}
	cout<<"N/A"<<endl;
	return;

}

int main(int argc, char* argv[])
{
	int N, M;
	cin>> N>> M;

	vector<student*> arr_student;
	int tmp[4];
	for ( unsigned int i=0; i<N; i++)
	{
		for ( unsigned int j=0; j<4; j++)
		{
			cin>>tmp[j];
		} 
		student *p_stu = new student(tmp);
		arr_student.push_back(p_stu);

		

	}


	solve(arr_student);
	
	
	int *output_student = new int[M];
	//output
	for (unsigned int i=0; i<M; i++)
	{
		cin>>output_student[i];
	}

	for (unsigned int i=0; i<M; i++)
	{
		output_student_fun(arr_student, output_student[i]);
	}
	return 0;
}