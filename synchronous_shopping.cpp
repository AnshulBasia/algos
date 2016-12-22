#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <limits>
#include <cstring>
using namespace std;

int shops[1003];
int shortest_path[1003][1030];
vector<pair<int,int>> graph[1003];
set <pair<int,pair<int,int>>> queue;

void clearance(){
    memset(shops,0,sizeof(shops));
    for(int i=0;i<1003;i++){
        for(int j=0;j<1030;j++){
            shortest_path[i][j]=numeric_limits<int>::max()/2;
        }
    }
}
void inqueue(int node,int mask,int cost){
    if(shortest_path[node][mask]<=cost){
        return;
    }
    pair<int,pair<int,int>> current = make_pair(shortest_path[node][mask],make_pair(node,mask));
    auto it = queue.find(current);
    if(it!=queue.end()){
        queue.erase(it);
    }
    shortest_path[node][mask]=cost;
    current.first=cost;
    queue.insert(current);
                                        
}

void dijkstra(int source){
    inqueue(source,shops[source],0);
    while(!queue.empty()){
        int cost = queue.begin()->first;
        int state = queue.begin()->second.second;
        source = queue.begin()->second.first;
        queue.erase(queue.begin());
        
        for(int i=0;i<graph[source].size();i++){
            inqueue(graph[source][i].first,state|shops[graph[source][i].first],graph[source][i].second+cost);
        }
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int nshops,nroads,nfish,t,x,y,c;
    cin>>nshops>>nroads>>nfish;
    clearance();
    for(int i=1;i<=nshops;i++){
        cin>>t;
        while(t--){
            cin>>x;
            shops[i]|=1<<(x-1);
        }
    }
    for(int i=0;i<nroads;i++){
        cin>>x>>y>>c;
        graph[x].emplace_back(y,c);
        graph[y].emplace_back(x,c);
    }
    
    dijkstra(1);
    int best_time = numeric_limits<int>::max();
    for(int i=0;i<(1<<nfish);i++){
        for(int j=i;j<(1<<nfish);j++){
           if((i|j)==(1<<nfish)-1){ 
               best_time=min(best_time,max(shortest_path[nshops][i],shortest_path[nshops][j]));
           }
            
        }
        
    }
    cout<<best_time<<endl;
}
