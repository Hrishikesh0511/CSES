// Your task is to count the number of ways numbers 1,2,\ldots,n can be divided into two sets of equal sum.
// For example, if n=7, there are four solutions:

// \{1,3,4,6\} and \{2,5,7\}
// \{1,2,5,6\} and \{3,4,7\}
// \{1,2,4,7\} and \{3,5,6\}
// \{1,6,7\} and \{2,3,4,5\}

// Input
// The only input line contains an integer n.
// Output
// Print the answer modulo 10^9+7.
// Constraints

// 1 \le n \le 500

// Example
// Input:
// 7

// Output:
// 4
//Approach:
//Solved by using the fact that it can only be divided into two halves if and only if it is even 
//So when it is even ,I would find number of sets that are equal to half of the total sum 
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
int f(int indx,vector<ll> &arr,ll target,vector<vector<ll>> &dp){
    if(indx==-1){
        return (target==0);
    }
    if(dp[indx][target]!=-1) return dp[indx][target];
    ll take=0,nottake=0;
    if(arr[indx]<=target){
        take=f(indx-1,arr,target-arr[indx],dp);
    }
    nottake=f(indx-1,arr,target,dp);
    return dp[indx][target]=((take+nottake)>2000000014)?(take+nottake)%mod:(take+nottake);
}
int main(){
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(int i=0;i<n;i++){
        arr[i]=i+1;
    }
    ll target=n*(n+1)/2;
    if(target%2==1) {
        cout<<0<<endl;
        return 0;
    }
    target=target/2;
    vector<vector<ll>> dp(n,vector<ll> (target+1,-1));
    cout<<(f(n-1,arr,target,dp)/2)<<endl;
}