// There is a list of n numbers and two players who move alternately. On each move, a player removes either the first or last number from the list, and their score increases by that number. Both players try to maximize their scores.
// What is the maximum possible score for the first player when both players play optimally?
// Input
// The first input line contains an integer n: the size of the list.
// The next line has n integers x_1,x_2,\ldots,x_n: the contents of the list.
// Output
// Print the maximum possible score for the first player.
// Constraints

// 1 \le n \le 5000
// -10^9 \le x_i \le 10^9

// Example
// Input:
// 4
// 4 5 1 3

// Output:
// 8

#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll maxsum(int start,int end,vector<ll> &arr,vector<vector<ll>> &dp){
    if(start>end){
        return 0;
    }
    if(dp[start][end]!=-1) return dp[start][end];
    ll first=arr[start]+min(maxsum(start+2,end,arr,dp),maxsum(start+1,end-1,arr,dp));
    ll last=arr[end]+min(maxsum(start,end-2,arr,dp),maxsum(start+1,end-1,arr,dp));
    //but why are we taking the minimum?
    //Because second player always play optimally so that we get the minimum one 
    return dp[start][end]=max(first,last);

}
int main(){
    int n;
    cin>>n;
    vector<ll> arr(n);
    for(int i=0;i<n;i++){
        cin>> arr[i];
    }
    vector<vector<ll>> dp(n,vector<ll> (n,-1));
    cout<<maxsum(0,n-1,arr,dp)<<endl;
}
