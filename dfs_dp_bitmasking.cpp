#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <map>
#include <list>

#define const 100;
void bfs(map<int,vector<int> > g,int n,int paths[100][100])
{
	bool visited[100]={false};
	
		
	visited[n]=true;
	list<int> q;
	q.push_back(n);
	int p=0;
	int x=n;
	int z;
	map<int,int> pred;
	cout<<"traversing node"<<n<<endl;
	while(!q.empty())
	{
		n=q.front();
		q.pop_front();
		
		
		for(int i=0;i<g[n].size();i++)
		{
			//cout<<"edge "<<g[n][i]<<endl;
			
			if(visited[g[n][i]]==1&&q.size()==0){break ;}
			
			if(visited[g[n][i]]==0)
			{
				
				visited[g[n][i]]=true;
				q.push_back(g[n][i]);
				pred[g[n][i]]=n;
				cout<<"pred of "<<g[n][i]<<" is "<<n<<endl;
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
			//cout<<temp<<" ";
			p++;
			if(temp==it->first){flag=1;break;}
		}
		if(flag==1){flag=0;paths[n][it->first]=-1;continue;}
		paths[x][it->first]=p;
		cout<<"path from "<<x<<"to"<<it->first<<"="<<p<<endl;
		p=0;
	}
	pred.clear();
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
	int mask=0;
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
	int paths[100][100];
	for(int i=0;i<g.size();i++)
	{
		for(int j=0;j<g.size();j++)
		{
			paths[i][j]=-1;
		}
		cout<<endl;
	}
	cout<<g[6].size()<<" "<<g[6][0]<<" "<<g[6][1];
	map<int,vector<int> >::iterator it = g.begin();
	for(;it!=g.end();++it)
	{
		bfs(g,it->first,paths);
	}

	cout<<"size"<<g.size()<<endl;

	for(int i=0;i<g.size();i++)
	{
		for(int j=0;j<g.size();j++)
		{
			cout<<paths[i][j]<<" ";
		}
		cout<<endl;
	}


}