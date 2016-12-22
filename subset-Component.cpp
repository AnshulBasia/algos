#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int parent[64];
int find(int parent[],int x){
    if(parent[x]==-1){return x;}
    return find(parent,parent[x]);
}

void unionn(int parent[],int x,int y){
    if(x==y){return;}
    int a=find(parent,x);
    int b=find(parent,y);
    parent[a]=b;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    long long d[24],temp;
    for(int i=0;i<n;i++){cin>>d[i];}
    long long mask = (1<<n);
    long long count,total=0;
    
    bool visited[64];
    for(long long i=0;i<mask;i++){
        memset(&parent,-1,sizeof(parent));
        for(int j=0;j<n;j++){
            if((i>>j)==0){break;}
            if((i>>j)&1){
                //d[j] is present in the subset
             
                int t=0;
                for(int k=0;k<64;k++){
                    if((d[j]>>k)&1){
                        t=k;
                        break;
                    }
                }
                
                for(int k=t+1;k<64;k++){
                    if((d[j]>>k)&1){
                       
                        unionn(parent,t,k);
                    }
                }
            }
        }
        //counting in the graph
        count=0;
        int temp;
        memset(&visited,false,sizeof(visited));
        for(int q=0;q<64;q++){
            if(!visited[q]){
                visited[q]=true;
                temp=q;
                while(parent[q]!=-1){
                    q=parent[q];
                    visited[q]=true;
                }
                q=temp;
                count++;
            }
        }
        //cout<<i<<" "<<count<<endl;
        total+=count;
    }
    cout<<total<<endl;
    return 0;
}
