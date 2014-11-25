#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
	//freopen("sample.in", "r", stdin);

	int ns, nc;
	cin>>ns>> nc;

	unordered_map<string, vector<int>*> umaps;
	for(int i=0; i<nc; i++)
	{
		int course_id, stu_n;
		cin>>course_id>>stu_n;

		for(int j=0; j<stu_n; j++)
		{
			string tmp_name;
			cin>>tmp_name;
			if(umaps.find(tmp_name)==umaps.end())
			{
				vector<int>* v1 = new vector<int>;
				umaps[tmp_name] = v1;
			}
			umaps[tmp_name]->push_back(course_id);
		}
	}

	//string output;
	//getchar();
	//getline(cin, output);
	for(int i=0; i<ns; i++)
	{
		string tmp;
		cin>>tmp;
		vector<int> * v0 = umaps[tmp];
		cout<<tmp;
		if(v0)
		{
			cout<<" "<<v0->size();
			sort(v0->begin(), v0->end());
			for(int j=0; j<v0->size(); j++)
				cout<<" "<<(*v0)[j];
		}
		else
		{
			cout<<" 0";
		}
		cout<<endl;
	}
	return 0;
}