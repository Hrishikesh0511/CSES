/*You know that an array has n integers between 1 and  m, and the absolute difference between two adjacent values is at most 1.
Given a description of the array where some values may be unknown, your task is to count the number of arrays that match the description.
Input
The first input line has two integers n and m: the array size and the upper bound for each value.
The next line has n integers x_1,x_2,\dots,x_n: the contents of the array. Value 0 denotes an unknown value.
Output
Print one integer: the number of arrays modulo 10^9+7.
Constraints

1 \le n \le 10^5
1 \le m \le 100
0 \le x_i \le m

Example
Input:
3 5
2 0 2

Output:
3

Explanation: The arrays [2,1,2], [2,2,2] and [2,3,2] match the description.*/
#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long cntarrays(int indx,int k,vector<int> &arr,int m,vector<vector<long long>> &dp){
    if(indx==-1){
        return 1;
    }
    //we can assume the problem like this 
    //every 0 depends on the right side of the element let's say'k' it has three choices 'k-1','k','k+1'
    // Edge cases:
    //if k is something like 1 =>'1' or '2'
    //k is 'm' => 'm' or 'm-1'
    // here k for every index is arr[indx+1]
    if(dp[indx][k]!=-1) return dp[indx][k];
    if(arr[indx]==0){
        if(k==1){
            return dp[indx][k]=(cntarrays(indx-1,k,arr,m,dp)+cntarrays(indx-1,k+1,arr,m,dp))%mod;
        }
        else if(k==m){
            return dp[indx][k]=(cntarrays(indx-1,k-1,arr,m,dp)+cntarrays(indx-1,k,arr,m,dp))%mod;
        }
        return dp[indx][k]=(cntarrays(indx-1,k-1,arr,m,dp)+cntarrays(indx-1,k,arr,m,dp)+cntarrays(indx-1,k+1,arr,m,dp))%mod;
    }
    else{
        if(abs(arr[indx]-k)<=1){
            return dp[indx][k]=(cntarrays(indx-1,arr[indx],arr,m,dp))%mod;
        }
        else{
            return dp[indx][k]=0;
        }
    }

}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> arr(n,0);
    vector<vector<long long>> dp(n+1,vector<long long> (m+1,-1));
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    long long count=0;
    if(arr.back()!=0)
    count=cntarrays(arr.size()-2,arr.back(),arr,m,dp);
    else{
    for(int i=1;i<=m;i++){
        count=(count+cntarrays(arr.size()-2,i,arr,m,dp))%mod;
    }
    }
    // for(int i=0;i<=n;i++){for(int j=0;j<=m;j++){
    //     cout<<dp[i][j]<<" ";
    // }
    // cout<<endl;
    // }
    cout<<count<<endl;
}