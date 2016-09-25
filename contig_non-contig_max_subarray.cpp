#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t;
    cin>>t;
    int n,a;
    vector<int> v;
    long long sum1=0;
    long long sum2=0;
    long long cur_sum;
    while(t>0){
        t--;
        sum1=0;
        sum2=0;
        v.clear();
        cin>>n;
        cur_sum=0;
        int flag=0;
        int flagg=0;
        for(int i=0;i<n;i++){
            cin>>a;
            if(a>0){flagg=1;sum2+=a;}
            if(cur_sum+a>0){cur_sum+=a;}
            else{cur_sum=0;}
            if(cur_sum>sum1){sum1=cur_sum;flag=1;}
            v.push_back(a);
        }
        
        if(flag==0){
            cout<<*max_element(v.begin(),v.end());
        }
        else{
            cout<<sum1;
        }
        if(flagg==0){
            cout<<" "<<*max_element(v.begin(),v.end())<<endl;
        }
        else{
            cout<<" "<<sum2<<endl;
        }
        
        
        
        
        
    }
    return 0;
}
