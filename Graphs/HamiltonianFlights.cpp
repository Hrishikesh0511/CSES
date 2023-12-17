// There are n cities and m flight connections between them. You want to travel from Syrjälä to Lehmälä so that you visit each city exactly once. How many possible routes are there?
// Input
// The first input line has two integers n and m: the number of cities and flights. The cities are numbered 1,2,\dots,n. City 1 is Syrjälä, and city n is Lehmälä.
// Then, there are m lines describing the flights. Each line has two integers a and b: there is a flight from city a to city b. All flights are one-way flights.
// Output
// Print one integer: the number of routes modulo 10^9+7.
// Constraints

// 2 \le n \le 20
// 1 \le m \le n^2
// 1 \le a,b \le n

// Example
// Input:
// 4 6
// 1 2
// 1 3
// 2 3
// 3 2
// 2 4
// 3 4

// Output:
// 2
#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    queue<int> q;
    q.push(1);
    vector<int> vis(n+1,0);
    long long routes=1;
    while(!q.empty()){
        int ele=q.front();
        vis[ele]=1;
        q.pop();
        long long cnt=0;
        for(auto it:adj[ele]){
            if(!vis[it]){
                cnt++;
            }
        }
        routes=(routes*cnt)%mod;
    }
    cout<<routes<<endl;
}