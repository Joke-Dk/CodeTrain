#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
class people;
unordered_map< string, people*> umaps;
class people
{
public:
	string _name;
	unordered_map<people* , int> _friends;
	bool _visited;
	int max_weight;

	people(string name)
	{
		_name = name;
		_visited = 0;
		max_weight = 0;
	}
	void add(string name2, int call_time)
	{
		if(_friends.find( umaps[name2]) == _friends.end())
		{
			_friends[umaps[name2]] = call_time;
		}
		else
		{
			_friends[umaps[name2]] += call_time;
		}
		max_weight+=call_time;
	}

};

vector<people* > cur_gang;
void travel(people* p, int& weight, people* pre)
{
	weight = 0;
	if(p->_visited)
		return;
	p->_visited = 1;
	cur_gang.push_back(p);
	for(unordered_map<people*, int>::iterator it = p->_friends.begin(); it != p->_friends.end(); it++ )
	{
		if(! it->first->_visited)
		{
			int tmp_weight;
			travel( it->first, tmp_weight, p);
 			weight += tmp_weight;
			weight += it->second;
			
		}
		else if(it->first != pre)
		{
			weight += it->second;
		}
	}
}

bool cmp(people *p1, people* p2)
{
	return p1->max_weight<p2->max_weight;
}

int main()
{
	freopen("sample2.in", "r", stdin);

	int N, limit;
	cin>>N>>limit;


	for(int i=0; i<N;i++)
	{
		string name0[2];
		int ptime;
		cin>>name0[0]>>name0[1]>>ptime;

		//malloc memory
		for(int j=0; j<2; j++)
		{
			if(umaps.find(name0[j])== umaps.end())
			{
				umaps[name0[j]] = new people(name0[j]);
			}
			
		}

		//build the people class
		for(int j=0; j<2; j++)
		{
			umaps[name0[j]]->add( name0[1-j], ptime);
		}

	}
	int weight = 0;
	vector<people *> heads;
	vector<int> heads_weight;
	for(unordered_map< string, people*>::iterator it = umaps.begin(); it!= umaps.end(); it++)
	{
		if(!it->second->_visited)
		{
			cur_gang.clear();
			travel(it->second, weight, NULL);
			if(cur_gang.size()>2 && weight>limit)
			{
				people* pmax = *max_element(cur_gang.begin(), cur_gang.end(), cmp);
				heads.push_back(pmax);
				heads_weight.push_back(cur_gang.size());
			}
		}
	}

	cout<<heads.size()<<endl;
	for(int i=0;i <heads.size(); i++)
	{
		cout<<heads[i]->_name<<" "<<heads_weight[i]<<endl;
	}
	return 0;

}