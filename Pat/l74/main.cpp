#include <iostream>


using namespace std;

pair<int, int> arrs[1000000];

int find_index(int head, int index)
{
	int cur = head;
	for(int i=0; i<index; i++)
	{
		cur = arrs[cur].second;
	}
	return cur;
}
int reverse_list(int head)
{
	int pre = -1;
	int cur = head;
	
	while(cur != -1)
	{
		int next = arrs[cur].second;
		arrs[cur].second = pre;
		pre = cur;
		cur = next;
	}
	return pre;
}

void output(int head)
{
	if(head==-1)
		return;
	//cout<<head<<" "<<arrs[head].first<<" "<<arrs[head].second<<endl;

	printf("%05d %d ", head, arrs[head].first);
	if(arrs[head].second==-1)
		cout<<"-1"<<endl;
	else
		printf("%05d\n", arrs[head].second);
	output(arrs[head].second);
}

int main()
{
	freopen("sample.in","r", stdin);

	int phead, N, K;

	cin>>phead>>N>>K;

	for(int i=0; i<N; i++)
	{
		int p, id, next;
		cin>>p>>id>>next;
		arrs[p] = make_pair(id, next);
	}
	int phead2 = find_index(phead, K);
	int pend1 = find_index(phead, K-1);
	arrs[pend1].second = -1;

	int new_h1 = reverse_list(phead);
	//int new_h2 = reverse_list(phead2);
	arrs[find_index(new_h1, K-1)].second = new_h2;

	output(new_h1);

	return 0;
}