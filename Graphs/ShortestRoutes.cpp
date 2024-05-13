#include<bits/stdc++.h>
#define inf 1e15
#define ll long long
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> adj[n+1];
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push({0,1});
    vector<ll> costs(n+1,inf);
    vector<ll> vis(n+1,0);
    vis[1]=1;
    costs[1]=0;
    while(!pq.empty()){
        ll node=pq.top().second;
        ll cost=pq.top().first;
        pq.pop();
        if(cost>costs[node]){
            continue;
        }
        for(auto it:adj[node]){
            if(it.second+cost<costs[it.first]){
                costs[it.first]=it.second+cost;
                pq.push({it.second+cost,it.first});
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<costs[i]<<" ";
    }
}