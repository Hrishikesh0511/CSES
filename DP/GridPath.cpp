// Consider an n \times n grid whose squares may have traps. It is not allowed to move to a square with a trap.
// Your task is to calculate the number of paths from the upper-left square to the lower-right square. You can only move right or down.
// Input
// The first input line has an integer n: the size of the grid.
// After this, there are n lines that describe the grid. Each line has n characters: . denotes an empty cell, and * denotes a trap.
// Output
// Print the number of paths modulo 10^9+7.
// Constraints

// 1 \le n \le 1000

// Example
// Input:
// 4
// ....
// .*..
// ...*
// *...

// Output:
// 3
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll f(int i,int j,vector<string> &grid,vector<vector<int>> &dp){
    int n=grid.size();
    if(i==n-1 && j==n-1) return grid[i][j]=='.';
    if(dp[i][j]!=-1) return dp[i][j];
    //down
    ll down=0,right=0;
    if(i+1<n && grid[i][j]=='.'){
        down=(down+f(i+1,j,grid,dp))%mod;
    }
    //right
    if(j+1<n && grid[i][j]=='.'){
        right=(right+f(i,j+1,grid,dp))%mod;
    }
    return dp[i][j]=(right+down)%mod;
}
int main(){
    int n;
    cin>>n;
    vector<string> grid(n,"");
    for(auto &i:grid) cin>>i;
    vector<vector<int>> dp(n,vector<int>(n,-1));
    cout<<f(0,0,grid,dp)<<endl;
}