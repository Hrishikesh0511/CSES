// Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to calculate the number of distinct ways you can produce a money sum x using the available coins.
// For example, if the coins are \{2,3,5\} and the desired sum is 9, there are 8 ways:

// 2+2+5
// 2+5+2
// 5+2+2
// 3+3+3
// 2+2+2+3
// 2+2+3+2
// 2+3+2+2
// 3+2+2+2

// Input
// The first input line has two integers n and x: the number of coins and the desired sum of money.
// The second line has n distinct integers c_1,c_2,\dots,c_n: the value of each coin.
// Output
// Print one integer: the number of ways modulo 10^9+7.
// Constraints

// 1 \le n \le 100
// 1 \le x \le 10^6
// 1 \le c_i \le 10^6

// Example
// Input:
// 3 9
// 2 3 5

// Output:
// 8

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
ll f(int target,vector<int> &arr){
    int n=arr.size();
    vector<ll> dp(target+1,0);
    dp[0]=1;
    for(int j=0;j<=target;j++){
    for(int indx=1;indx<=n;indx++){
              if(j>=arr[indx-1]){
                dp[j]=(dp[j]+dp[j-arr[indx-1]])%mod;
              }
            }
    }
    return dp[target];
}
int main(){
    int n,target;
    cin>>n>>target;
    vector<int> arr(n);
    for(auto &i:arr) cin>>i;   
    cout<<f(target,arr)<<endl;
}