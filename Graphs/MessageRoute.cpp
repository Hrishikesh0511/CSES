// Syrjälä's network has n computers and m connections. Your task is to find out if Uolevi can send a message to Maija, and if it is possible, what is the minimum number of computers on such a route.
// Input
// The first input line has two integers n and m: the number of computers and connections. The computers are numbered 1,2,\dots,n. Uolevi's computer is 1 and Maija's computer is n.
// Then, there are m lines describing the connections. Each line has two integers a and b: there is a connection between those computers.
// Every connection is between two different computers, and there is at most one connection between any two computers.
// Output
// If it is possible to send a message, first print k: the minimum number of computers on a valid route. After this, print an example of such a route. You can print any valid solution.
// If there are no routes, print "IMPOSSIBLE".
// Constraints

// 2 \le n \le 10^5
// 1 \le m \le 2 \cdot 10^5
// 1 \le a,b \le n

// Example
// Input:
// 5 5
// 1 2
// 1 3
// 1 4
// 2 3
// 5 4

// Output:
// 3
// 1 4 5
#include<bits/stdc++.h>
using namespace std;
int possible=false;
void bfs(int src,int des,vector<int> adj[],vector<int> &vis){ 
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int node=q.front();
        if(node==des){
            possible=true;
            return ;
        }
        q.pop();
        for(auto it:adj[node]){
            if(!vis[it]){
                vis[it]=node;   //instead of making it as visited just store the parent node to backtrack the route at the end
                q.push(it);
            }
        }
    }

}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    while(m--){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
     vector<int> vis(n+1,0);  
    //do a bfs from source to destination
    bfs(1,n,adj,vis);
    if(!possible){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    vector<int> route;
    //backtrack to get the route
    int node=n;
    route.push_back(node);
    while(node!=1){
        node=vis[node];
        route.push_back(node);
    }
    reverse(route.begin(),route.end());
    cout<<route.size()<<endl;
    for(auto it:route) cout<<it<<" ";
}