#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

//#include <stdc++.h>
using namespace std;



class book
{
public:
	int ID;
	vector<string> keys;
	void input()
	{
		cin>>ID;
		getchar();
		for(int i=0; i<5; i++)
		{
			string tmp;
			getline(cin, tmp);
			keys.push_back(tmp);
		}
	}

	bool search(string str, int index)
	{
		
		size_t found = keys[index].find( str);
			
		//if(keys[str.begin()found]);
		if(found != string::npos)
		{
			string tmp_str = keys[index].substr(found+str.length(), 1);
			bool tmp_flag01 = 1;
			if(found != 0)
				tmp_flag01 = (keys[index].substr(found-1, 1) == " ");
			bool tmp_flag02 = (tmp_str==" " || tmp_str=="");
			if (tmp_flag01 && tmp_flag02)
			{
				return 1;
			}
		}
				
		
		return 0;
	}
};

vector<book *> books;

bool cmp_book(book* b1, book* b2)
{
	return b1->ID < b2->ID;
}

int main()
{
	//freopen("sample.in", "r", stdin);

	int N, Q;
	cin>>N;
	
	for(int i=0;i<N; i++)
	{
		book * tmp = new book();
		tmp->input();
		books.push_back(tmp);

	}

	sort(books.begin(), books.end(), cmp_book);
	cin>>Q;
	getchar();
	for(int i=0; i<Q; i++)
	{
		bool flag_found = 0;
		string search_key;
		
		getline(cin, search_key);
		cout<<search_key<<endl;
		int search_index = atoi(const_cast<char*>(search_key.substr(0, 1).c_str()));
		search_key = search_key.substr(3);
		for(int j=0; j<N; j++)
		{
			if(books[j]->search(search_key, search_index-1))
			{
				cout<<books[j]->ID<<endl;
				flag_found = 1;
			}
		}
		if(!flag_found)
		{
			cout<<"Not Found"<<endl;
		}
	}
	return 0;
}