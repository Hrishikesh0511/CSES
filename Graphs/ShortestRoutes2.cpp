#include<bits/stdc++.h>
#define inf 1e14
#define ll long long
using namespace std;
int main(){
    int n,m,q;
    cin>>n>>m>>q;
    //cost matrix
    vector<vector<ll>> cost(n+1,vector<ll> (n+1,inf));
    //from and to are same,then the cost is 0
    for(int i=1;i<=n;i++) cost[i][i]=0;

    while(m--){
        ll u,v,c;
        cin>>u>>v>>c;
        cost[u][v]=min(cost[u][v],c);//minimum to handle the case where there are multiple edges between two nodes
        //two way
        cost[v][u]=min(cost[u][v],c);
    }

    for(int k=1;k<=n;k++){
        //via k
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
            }
        }
    }
    //handling queries
    while(q--){
        int u,v;
        cin>>u>>v;
        if(cost[u][v]>=inf){
            cout<<-1<<endl;
        }
        else{
            cout<<cost[u][v]<<endl;
        }
    }
    return 0;

}