// Byteland has n cities and m roads between them. Your task is to design a round trip that begins in a city, goes through two or more other cities, and finally returns to the starting city. Every intermediate city on the route has to be distinct.
// Input
// The first input line has two integers n and m: the number of cities and roads. The cities are numbered 1,2,\dots,n.
// Then, there are m lines describing the roads. Each line has two integers a and b: there is a road between those cities.
// Every road is between two different cities, and there is at most one road between any two cities.
// Output
// First print an integer k: the number of cities on the route. Then print k cities in the order they will be visited. You can print any valid solution.
// If there are no solutions, print "IMPOSSIBLE".
// Constraints

// 1 \le n \le 10^5
// 1 \le m \le 2 \cdot 10^5
// 1 \le a,b \le n

// Example
// Input:
// 5 6
// 1 3
// 1 2
// 5 3
// 1 5
// 2 4
// 4 5

// Output:
// 4
// 3 5 1 3
#include<bits/stdc++.h>
using namespace std;
int start=-1;
bool dfs(int node, int parent, vector<int> adj[], vector<int> &vis, vector<int> &par) {
    for (auto it : adj[node]) {
        if (vis[it] && it != parent) {
            start=it;
            par[it] = node;
            return true;
        } else if (!vis[it]) {
            vis[it] = 1;
            par[it] = node;
            if (dfs(it, node, adj, vis, par))
                return true;
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    int flag = 0;

    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> vis(n + 1, 0);
    vector<int> par(n + 1, 0); 
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            if (dfs(i, -1, adj, vis, par)) {
                flag = 1;
                break;
            }
        }
    }

    if (!flag) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    vector<int> rt;
    rt.push_back(start);
    int loc=par[start];
    while(loc!=start){
        rt.push_back(loc);
        loc=par[loc];
    }
    rt.push_back(start);
    cout<<rt.size()<<endl;
    reverse(rt.begin(),rt.end());
    for(auto it:rt){
        cout<<it<<" ";
    }
    return 0;
}

