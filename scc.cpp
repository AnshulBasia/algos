#include<fstream>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
#include<stack>



const long long n=875715;   //number of nodes +1....since 0th location wasted

vector<bool> explored;

int t=0;
long long z;


void dfs(vector< vector<int> > g, int s,stack<int> &s)
{
	explored[s]=true;
	for(int i=0;i<g[s].size();i++)
	{
		if(!explored[g[s][i]]){dfs(g,g[s][i],s);}
	}
	s.push(s);
}

void dfs_rev(vector< vector<int> > g,int s,vector<int> temp)
{
	explored[s]=true;
	temp.push_back(s);
	for(int i=0;i<g[s].size();i++)
	{
		if(!explored[g[s][i]]){dfs_rev(g,g[s][i],temp);}
	}
}

int main()
{
    cout<<"starting the program";
    vector<vector<int> > g;
   
    vector<vector<int> >g_rev;
    vector<vector<int> >final;
    vector<int> temp;
    temp.push_back(0);
    for(int i=0;i<n;i++)
    {
        g.push_back(temp);
        g_rev.push_back(temp);
        final.push_back(temp);
        f_time.push_back(0);
        f.push_back(0);
    }


   for(int i=0;i<n;i++){explored.push_back(false); }

   ifstream file("SCC.txt");
   string str;
   vector<long> l;
   long r=0;

   while(getline(file,str,'\n'))
   {

       if(str.length()==0){continue;}
       for(int k=0;k<str.length();k++)
       {
           if(str[k]==' ')
           {
               l.push_back(r);
               r=0;
           }
           else
           {
               r=(10*r)+(static_cast<int>(str[k])-48);

               if(k==str.length()-1){l.push_back(r); r=0;}
           }
       }

       //constructing g
       if(g[l[0]][0]==0){g[l[0]].clear();}
       g[l[0]].push_back(l[1]);
       //constructing reversed graph
       if(g_rev[l[1]][0]==0){g_rev[l[1]].clear();}
       g_rev[l[1]].push_back(l[0]);
      // cout<<l[0]<<" "<<l[1]<<endl;
       l.clear();
   }
   for(int i=0;i<n;i++)
    {
        if(g[i][0]==0){g[i].clear();}
        if(g_rev[i][0]==0){g_rev[i].clear();}
    }
   /*for(int i=1;i<n;i++)
   {
       cout<<i<<"    ->";
       for(int j=0;j<g[i].size();j++)
       {
           cout<<g[i][j]<<" ";
       }
       cout<<endl;
   }
   for(int i=1;i<n;i++)
   {
       cout<<i<<"    ->";
       for(int j=0;j<g_rev[i].size();j++)
       {
           cout<<g_rev[i][j]<<" ";
       }
       cout<<endl;
   }*/
	
   stack<int> s;
   for(i=1;i<n;i++)
   {
	if(!explored[i]){dfs(g,i,stack);}
   }


   for(int i=0;i<n;i++){explored.push_back(false); }
   vector< vector<int> > answer;
   vector<int> tempp;

   while(!s.empty())
   {
	int v=s.top();
	s.pop();
	if(!explored[v]){dfs_rev(g_rev,v,tempp); answer.push_back(tempp);tempp.clear();}
   }

   
  




}
