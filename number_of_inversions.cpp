#include<iostream>
#include<vector>
#include<algorithm>
#include <fstream>
using namespace std;

long long count_inversions(long long n, vector<long long> &v)
{
    if(n==1)
    {
        return 0;
    }
    if(n==2)
    {
        if(v[1]>=v[0])
        {
            return 0;
        }
        else
        {
            long long a=v[1];
            long long b=v[0];
            v.clear();
            v.push_back(a);
            v.push_back(b);
            return 1;
        }
    }

    vector<long long> v1;
    vector<long long> v2;
    for (long long i=0;i<n;i++)
    {

        if(i<n/2)
        {
            v1.push_back(v[i]);
        }
        else
        {
            v2.push_back(v[i]);
        }
    }
   v.clear();
   long long a=count_inversions(v1.size(),v1);
  // cout<<a<<v1.size()<<endl;
   long long b=count_inversions(v2.size(),v2);
  // cout<<b<<endl;
   long long inv=0;
   long long j,k=0;
   j=0;
   long long r=0;
   long long t=0;
   while(t<v2.size()&&r<v1.size())
   {
       if(v1[r]<=v2[t])
       {
           //inv+=v2.size()-t;
           r++;
       }
       else
       {
           inv+=v1.size()-r;
           //cout<<r<<" "<<v1[r]<<"in-"<<inv<<endl;
           //cout<<inv<<endl;
           t++;
       }
   }
   j=k=0;
   for(long long i=0;i<n;i++)
   {
        if(j==v1.size())
        {
           while(k!=v2.size())
           {
               v.push_back(v2[k]);
               k++;
           }
           break;
        }
        if(k==v2.size())
        {
            while(j!=v1.size())
            {
                v.push_back(v1[j]);
                j++;
            }
            break;
        }
       if(v1[j]<=v2[k])
       {
           v.push_back(v1[j]);
           j++;
       }
       else
       {
           v.push_back(v2[k]);
           k++;

       }

   }
   return inv+a+b;


}

int main()
{

    long long n=100000;
    ifstream file("test.txt");

    vector<long long> v;
    string str;
    while(getline(file,str,'\n'))
    {
        long long j;
        j=0;
        for(int k=0;k<str.length();k++)
        {
            //cout<<static_cast<int>(str[k])-48<<" "<<j;
            j=(10*j)+(static_cast<int>(str[k])-48);
            //cout<<" "<<j<<endl;
        }
        //cout<<j<<endl;
        v.push_back(j);
    }

    cout<<count_inversions(n,v);

}
