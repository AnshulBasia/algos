#include<fstream>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;



const long long n=875715;   //number of nodes +1....since 0th location wasted

vector<bool> explored;
int t=0;
long long z;
vector<long long> f_time;
vector<long long> f;


void dfs_t(vector<vector<int> >g,int i)
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

void dfs_s(vector<vector<int> >g,int i)
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
    vector<vector<int> > g;
    vector<long long> ans;
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


    for(int i=0;i<n;i++){explored.push_back(false);}

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

   int t=0;//finishing time
   cout<<done;

   for(long long i=n-1;i>=1;i--)
   {
       if(!explored[i])
       {
           dfs_t(g_rev,i);
       }
   }
   for(int i=1;i<n;i++)
   {
       final[i].clear();
       for(int j=0;j<g[f_time[i]].size();j++)
       {

             final[i].push_back(f[g[f_time[i]][j]]);
       }

   }
   cout<<"final graph with reversed and finishing times"<<endl;
   /*
   for(int i=1;i<n;i++)
   {
       cout<<i<<"    ->";
       for(int j=0;j<final[i].size();j++)
       {
           cout<<final[i][j]<<" ";
       }
       cout<<endl;
   }
   */
    for(int i=0;i<n;i++){explored[i]=false;}
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
   sort(ans.begin(),ans.end(),greater<int>());

   for(int i=0;i<5;i++)
   {
       if(i<ans.size())
       {
           cout<<ans[i]<<" ";
       }
   }




}
