// Given an a \times b rectangle, your task is to cut it into squares. On each move you can select a rectangle and cut it into two rectangles in such a way that all side lengths remain integers. What is the minimum possible number of moves?
// Input
// The only input line has two integers a and b.
// Output
// Print one integer: the minimum number of moves.
// Constraints

// 1 \le a,b \le 500

// Example
// Input:
// 3 5

// Output:
// 3
//here we have two choices everytime either to cut horizantally or vertically
#include<bits/stdc++.h>
using namespace std;
int f(int n,int m,vector<vector<int>> &dp){
   if(n==m) return 0;
   if(dp[n][m]!=-1) return dp[n][m];
   //horizontal cut
   int minh=1e7;
    for(int i=1;i<n;i++){
        minh=min(minh,1+f(n-i,m,dp)+f(i,m,dp));
    }
    //vertical cut
    int minv=1e7;
    for(int i=1;i<m;i++){
        minv=min(minv,1+f(n,m-i,dp)+f(n,i,dp));
    }
    return min(minv,minh);
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    cout<<f(n,m,dp)<<endl;
}