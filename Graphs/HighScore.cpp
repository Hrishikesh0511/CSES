#include<bits/stdc++.h>
#define ll long long
#define inf 1e14
using namespace std;
ll dfs(int node,vector<pair<ll,ll>> adj[],vector<int> &vis,int sum){
    if(node==vis.size()-1){
        return sum;
    }
    vis[node]=1;
    ll maxi=INT_MIN;
    for(auto it:adj[node]){
        ll adjnode=it.first;
        ll wt=it.second;
        if(!vis[adjnode]){
            maxi=max(maxi,dfs(adjnode,adj,vis,sum+wt));
            vis[adjnode]=0;
        }
    }
    return maxi;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<ll> dist(n+1,inf);
    vector<vector<ll>> edges;
    while(m--){
        ll a,b,c;
        cin>>a>>b>>c;
        edges.push_back({a,b,c});
    }
    //n-1 times 
    for(int i=0;i<n-1;i++){
        for(auto it:edges){
            ll u=it[0];
            ll v=it[1];
            ll d=-1*it[2];  //changed all pos to neg to find out the poscycle by bellman ford
            if(dist[u]+d<dist[v]){
                dist[v]=dist[u]+d;
            }
        }
    }
    int isPos=0;
    //nth time
    for(auto it:edges){
            ll u=it[0];
            ll v=it[1];
            ll d=-1*it[2];
            if(dist[u]+d<dist[v]){
                isPos=1;
                dist[v]=dist[u]+d;
            }
        }
    vector<pair<ll,ll>> adj[n+1];
    for(auto it:edges){
        adj[it[0]].push_back({it[1],it[2]});
    }
    vector<int> vis(n+1,0);
    if(!isPos){ //if there is no positive cycle you can safely find out the max distance by dfs
       cout<<dfs(1,adj,vis,0)<<endl;
       return 0;
    }
    cout<<-1<<endl;
}