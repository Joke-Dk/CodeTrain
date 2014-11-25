#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class record
{
public:
	string _id;
	int _score;
	int _location;
	int _location_rank;

	record(string id, int score, int location)
	{
		_id = id;
		_score = score; 
		_location = location;
	}

};

bool cmp_record(record* r1, record* r2)
{
	return r1->_score>r2->_score;
}

void output(record* r0, int cur_rank)
{
	cout<<r0->_id<<" "<<cur_rank<<" "<<r0->_location<<" "<<r0->_location_rank<<endl;
}

int main()
{
	//freopen("sample.in", "r", stdin);

	int K;

	cin>>K;
	vector<record*> whole_arrs;
	for(int i=0; i<K; i++)
	{
		int N;
		cin>>N;
		vector<record *> arrs;
		for(int j=0; j<N; j++)
		{
			string id;
			int score;
			cin>>id>>score;
		
			arrs.push_back(new record(id, score, i+1));
			
		}

		sort(arrs.begin(), arrs.end(), cmp_record);
		int pre_score = -1; int pre_rank = -1;
		for(int j=0; j<arrs.size(); j++)
		{
			if(arrs[j]->_score == pre_score)
			{
				arrs[j]->_location_rank = pre_rank;
			}
			else
			{
				arrs[j]->_location_rank = j+1;
				pre_score = arrs[j]->_score;
				pre_rank = j+1;
			}
		}
		whole_arrs.insert(whole_arrs.end(), arrs.begin(), arrs.end());
	}

	sort(whole_arrs.begin(), whole_arrs.end(), cmp_record);

	cout<<whole_arrs.size()<<endl;
	int pre_score = -1; int pre_rank = -1;
	for(int i=0; i<whole_arrs.size(); i++)
	{
		if(whole_arrs[i]->_score == pre_score)
		{
			output(whole_arrs[i], pre_rank);
		}
		else
		{
			output(whole_arrs[i], i+1);
			pre_score = whole_arrs[i]->_score;
			pre_rank = i+1;
		}
		
	}

	return 0;
}