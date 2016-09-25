#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long win(long long i,long long j,vector<long long> v){
    if(i==j){return -1;}
    for(long long k=i;k<=j;k++){
        if(v[k]==v[j]-v[k]){
            return k;
        }
    }
    return -1;
}
long long score(long long i,long long j,vector<long long> v,long long k){
    
    
    if(k==-1){return 0;}
    else{
        long long a=win(i,k,v);
        for(long long q=k+1;q<=j;q++){
            v[q]-=v[k];
        }
        long long b=win(k+1,j,v);
        if(a==-1&&b!=-1){return 1+score(k+1,j,v,b);}
        if(a!=-1&&b==-1){return 1+score(i,k,v,a);}
        if(a==-1&&b==-1){return 1;}
        long long c,d;
        c=score(k+1,j,v,b);
        d=score(i,k,v,a);
        if(c>=d){
            return 1+c;
        }
        else{
            return 1+d;
        }
        
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Prlong long output to STDOUT */   
    long long t;
    cin>>t;
    long long n,a,s;
    vector<long long> v,sum;
    while(t>0){
        t--;
        v.clear();
        sum.clear();
        s=0;
        cin>>n;
        for(long long i=0;i<n;i++){
            cin>>a;
            s+=a;
            v.push_back(a);
            sum.push_back(s);
        }
        
        if(s==0){cout<<n-1<<endl;}
        else{
            long long k=win(0,n-1,sum);
            cout<<score(0,n-1,sum,k)<<endl;
        }
        
        
    }
    return 0;
}
