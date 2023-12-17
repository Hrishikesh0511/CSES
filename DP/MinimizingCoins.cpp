// Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to produce a sum of money x using the available coins in such a way that the number of coins is minimal.
// For example, if the coins are \{1,5,7\} and the desired sum is 11, an optimal solution is 5+5+1 which requires 3 coins.
// Input
// The first input line has two integers n and x: the number of coins and the desired sum of money.
// The second line has n distinct integers c_1,c_2,\dots,c_n: the value of each coin.
// Output
// Print one integer: the minimum number of coins. If it is not possible to produce the desired sum, print -1.
// Constraints

// 1 \le n \le 100
// 1 \le x \le 10^6
// 1 \le c_i \le 10^6

// Example
// Input:
// 3 11
// 1 5 7

// Output:
// 3
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    cin>>n>>x;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<vector<int>> dp(n,vector<int> (x+1,-1));
    if(indx==-1) {
        if(target==0){
            return 0;
        }
        return 1e7;
    }
    if(dp[indx][target]!=-1) return dp[indx][target];
    int take=INT_MAX,nottake=INT_MAX;
    if(target>=arr[indx]){
        take=1+f(indx,target-arr[indx],arr,dp);
    }
    nottake=f(indx-1,target,arr,dp);
    return dp[indx][target]=min(take,nottake);
    if(ans>=1e7){
        cout<<-1<<endl;
    }
    else
    cout<<ans<<endl;
}