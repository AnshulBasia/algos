#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <map>
#include <list>
#include <bits/stdc++.h>

#define const 100;
int paths[10000][10000];
bool visited[10000];
void bfs(map<int,vector<int> > g,int n)
{
	//visited={false};
	memset(visited,false,sizeof(visited));
		
	visited[n]=true;
	list<int> q;
	q.push_back(n);
	int p=0;
	int x=n;
	int z;
	map<int,int> pred;
	//cout<<"traversing node"<<n<<endl;
	while(!q.empty())
	{
		n=q.front();
		q.pop_front();
		////cout<<"n "<<n<<endl;
		
		for(int i=0;i<g[n].size();i++)
		{
			////cout<<"edge "<<g[n][i]<<" "<<q.size()<<endl;
			////cout<<visited[g[n][i]]<<endl;
			
			if(visited[g[n][i]]==1&&q.size()==0){break ;}
			
			if(visited[g[n][i]]==0)
			{
				
				visited[g[n][i]]=true;
				q.push_back(g[n][i]);
				pred[g[n][i]]=n;
				////cout<<"pred of "<<g[n][i]<<" is "<<n<<endl;
			}
			
			
		}
		
		
	}
	
	int temp;
	int flag=0;
	map<int,vector<int> >::iterator it = g.begin();
	
	for(;it!=g.end();++it)
	{	
		//paths[x][n]=p;
		
		temp=it->first;
		
		if(temp==x){paths[n][x]=0;continue;}
		
		
		while(temp!=x)
		{
			temp=pred[temp];
			////cout<<temp<<" ";
			p++;
			if(temp==it->first){flag=1;break;}
		}

		if(flag==1){flag=0;paths[n][it->first]=-1;continue;}
		paths[x][it->first]=p;
		////cout<<"path from "<<x<<"to"<<it->first<<"="<<p<<endl;
		p=0;

	}

	pred.clear();
	//cout<<"x="<<x<<endl;
	
}
int dp[1000][1000];
void fill(int dirtt,int mask,vector<int> dirt_path)
{
	int min;
	//cout<<mask<<endl;
	int count=0;
	for(int l=0;l<dirtt;l++)
	{
		if(mask&(1<<l)){count++;}
	}
	if(count==dirtt-1){return;}
	
	
	for(int i=0;i<dirtt;i++)
	{
		//to fill dp[mask]
		
		if(!(mask&(1<<i)))
		{	
			fill(dirtt,mask|(1<<i),dirt_path);
			
			min=1000000;
			for(int j=0;j<dirtt;j++)
			{
				if(!(mask&(1<<j))&&j!=i&&paths[dirt_path[j]][dirt_path[i]]!=-1)
				{
					
					if(dp[mask|(1<<i)][j]==-1){continue;}
					if((dp[mask|(1<<i)][j])+paths[dirt_path[j]][dirt_path[i]]<min){min=dp[mask|(1<<i)][j]+paths[dirt_path[j]][dirt_path[i]];}
				}
			}
			if(min==1000000){dp[mask][i]=-1;}
			else{dp[mask][i]=min;}
			
		}
	}
}

int main()
{
	int w;
	int h;
	cin>>w>>h;
	int start;
	vector<int> dirt;
	map<int,vector<int> > g;
	char a[h][w];
	vector<int> v;

	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			cin>>a[i][j];
			if(a[i][j]=='o'){start=(w*i)+j;}
			if(a[i][j]=='*'){dirt.push_back((w*i)+j);}
		}
	}
	int no_of_dirt=dirt.size();
	int allmask=(1<<no_of_dirt)-1;

	int mask;
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{


				if(i!=h-1)
				{
					if(a[i+1][j]!='x')
					{
						v.push_back((w*(i+1))+j);
					}
				}
				if(i!=0)
				{
					if(a[i-1][j]!='x')
					{
						v.push_back((w*(i-1))+j);
					}
				}
				if(j!=w-1)
				{
					if(a[i][j+1]!='x')
					{
						v.push_back((w*i)+j+1);
					}
				}
				if(j!=0)
				{
					if(a[i][j-1]!='x')
					{
						v.push_back((w*i)+j-1);
					}
				}

				g[(w*i)+j]=v;
				v.clear();
			}	
		

	}
	
	for(int i=0;i<g.size();i++)
	{
		for(int j=0;j<g.size();j++)
		{
			paths[i][j]=-1;
		}
	}
	
	map<int,vector<int> >::iterator it = g.begin();
	for(;it!=g.end();++it)
	{
		//cout<<"ff"<<it->first<<endl;
		bfs(g,it->first);
		//cout<<"g";
	}

	//cout<<"size"<<g.size()<<endl;

	for(int i=0;i<g.size();i++)
	{
		for(int j=0;j<g.size();j++)
		{
			//cout<<paths[i][j]<<" ";
		}
		//cout<<endl;
	}
	
	memset(dp,-1,sizeof(dp));
	//cout<<endl;
	//cout<<allmask<<endl;

	for(int i=0;i<no_of_dirt;i++)
	{
		mask=allmask;
		mask=(mask) ^ ((1<<i));
		dp[mask][i]=paths[start][dirt[i]];

	}
	for(int i=0;i<allmask;i++)
	{
		for(int j=0;j<no_of_dirt;j++)
		{
			//cout<<dp[i][j]<<" ";

		}
		//cout<<endl;
	}
	mask=0;
	fill(no_of_dirt,mask,dirt);
	for(int i=0;i<allmask;i++)
	{
		for(int j=0;j<no_of_dirt;j++)
		{
			//cout<<dp[i][j]<<" ";
		}
		//cout<<endl;
	}
	int ans=dp[0][0];
	for(int i=1;i<no_of_dirt;i++)
	{
		if(dp[0][i]<ans){ans=dp[0][i];}
	}
	cout<<ans<<endl;
}