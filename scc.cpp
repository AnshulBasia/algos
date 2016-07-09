#include<fstream>
#include<vector>
#include<algorithm>
#include<iostream>

#include<string>
using namespace std;



const long long n=875715;   //number of nodes +1....since 0th location wasted
bool explored[n];
int t=0;
long long z;
long long f_time[n];
long long f[n];


void dfs_t(vector<int> g[n],int i)
{
    explored[i]=true;
    for(int j=0;j<g[i].size();j++)
    {
        if(!explored[g[i][j]])
        {
            dfs_t(g,g[i][j]);
        }

    }
    t++;
    f_time[t]=i;
    f[i]=t;
}

void dfs_s(vector<int> g[n],int i)
{
    explored[i]=true;
    for(int j=0;j<g[i].size();j++)
    {
        if(!explored[g[i][j]])
        {
            dfs_s(g,g[i][j]);
        }

    }
    z++;

}
int main()
{
    cout<<"hey";
    vector<int> g[n];
    vector<long long> ans;
    vector<int> g_rev[n];
    vector<int> final[n];

    fill_n(explored, n, false);

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
       g[l[0]].push_back(l[1]);
       //constructing reversed graph
       g_rev[l[1]].push_back(l[0]);
       cout<<l[0]<<" "<<l[1]<<endl;
       l.clear();
   }
   for(int i=1;i<n;i++)
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
   }

   int t=0;//finishing time
   for(long long i=n-1;i>=1;i--)
   {
       if(!explored[i])
       {
           dfs_t(g_rev,i);
       }
   }
   for(int i=1;i<n;i++)
   {
       for(int j=0;j<g[f_time[i]].size();j++)
       {
             final[i].push_back(f[g[f_time[i]][j]]);
       }

   }
   cout<<"final graph with reversed and finishing times"<<endl;
   for(int i=1;i<n;i++)
   {
       cout<<i<<"    ->";
       for(int j=0;j<final[i].size();j++)
       {
           cout<<final[i][j]<<" ";
       }
       cout<<endl;
   }
   fill_n(explored, n, false);
   z=0;
   for(int i=n-1;i>=1;i--)
   {
       if(!explored[i])
       {
           dfs_s(final,i);
           ans.push_back(z);
           z=0;
       }

   }
   sort(ans.begin(),ans.end());
   for(int i=ans.size()-1;i>=ans.size()-5;i--)
   {
       
           cout<<ans[i]<<" ";
      
   }




}
