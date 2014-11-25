#include<iostream>
#include<vector>
#include <iomanip>
using namespace std;
int main()
{	
	int K=0;
	vector<int> p1i;
	vector<float> p1f;
	vector<int> p2i;
	vector<float> p2f;

	//Line 1
	cin>>K;
	int index = 0;
	float value = 0.f;
	for(int j=0; j<K; j++)
	{
		cin>>index>>value;
		p1i.push_back(index);
		p1f.push_back(value);
	}
	//Line 2
	cin>>K;
	for(int j=0; j<K; j++)
	{
		cin>>index>>value;
		p2i.push_back(index);
		p2f.push_back(value);
	}

	//Add p1 and p2
	vector<int> pi;
	vector<float> pf;
	int i=0;
	int j=0;
	while(i<p1i.size() && j<p2i.size()){
		if(p1i[i]>p2i[j]){
			pi.push_back(p1i[i]);
			pf.push_back(p1f[i]);
			i++;
		}
		else if(p1i[i]<p2i[j]){
			pi.push_back(p2i[j]);
			pf.push_back(p2f[j]);
			j++;
		}
		else
		{
			pi.push_back(p1i[i]);
			pf.push_back(p1f[i]+p2f[j]);
			i++;
			j++;
		}
	}
	if(i>=p1i.size()){
		for(;j<p2i.size();j++){
			pi.push_back(p2i[j]);
			pf.push_back(p2f[j]);
		}
	}
	if(j>=p2i.size()){
		for(;i<p1i.size();i++){
			pi.push_back(p1i[i]);
			pf.push_back(p1f[i]);
		}
	}
	
	cout<<pi.size();
	cout<<fixed<<setprecision(1);  
	//cout<<" "<<i<<" "<<input[i];  
	for(int k=0; k<pi.size(); k++)
	{
		printf(" %d", pi[k]);
		//printf(" %.1f", pf[k]);
		cout<<" "<<pf[k];
	}
	return 0;




}