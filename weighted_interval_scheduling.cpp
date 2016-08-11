#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct job
{
	int i;
	int f;
	int w;
};
vector<bool> ans;

bool compare_f(const job &a, const job &b)
{ return a.f<b.f;}

int find_max(vector<job> v,int idx)
{
	cout<<idx<<endl;
	if(idx==-1){return 0;}
	if(idx==0){ ans[0]=true;return v[0].w;}
	if(idx==1)
	{
		if(v[1].i<v[0].f)
		{
			if(v[1].w>v[0].w){ans[0]=false; ans[1]=true; return v[1].w;} else{ans[0]=true; ans[1]=false; return v[0].w;}
		}
		else{ans[0]=true; ans[1]=true; return v[1].w+v[0].w;}
	}	
	int k;	
	for(int j=idx-1;j>=-1;j--)
	{
		if(v[j].f<=v[idx].i)
		{
			k=j;
			break;
		}
	}
	int a=find_max(v,idx-1);
	int b=v[idx].w+find_max(v,k);
	if(b>a)
	{
		ans[idx]=true;
		for(int j=idx-1;j>k;j--)
		{
			ans[j]=false;
		}
		return b;
	}
	else
	{
		ans[idx]=false;
		return a;
	}
	
}
int main()
{
	vector<job> jobs;
	int weight;
	cout<<"Enter the number of jobs"<<endl;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		job j;		
		cout<<"enter starting time"<<endl;
		cin>>j.i;
		cout<<"Enter finishing time"<<endl;
		cin>>j.f;
		cout<<"enter weight of job"<<endl;
		cin>>j.w;
		jobs.push_back(j);
	}

	//SORTING JOBS ON THE BASIS OF THEIR FINISHING TIME IN INCREASING ORDER
	
	sort(jobs.begin(),jobs.end(),compare_f);

	//initialise ans with false
	for(int i=0;i<n;i++){ans.push_back(false);}

	vector<job> final_jobs;
	weight=find_max(jobs,n-1);
	cout<<"Maximum profit-"<<weight<<endl;
	cout<<"List of job indices=";
	
	for(int i=0;i<n;i++)
	{
		if(ans[i]){cout<<i+1<<"  ";}
	}


	
}


