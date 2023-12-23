// You are given an array containing n integers. Your task is to determine the longest increasing subsequence in the array, i.e., the longest subsequence where every element is larger than the previous one.
// A subsequence is a sequence that can be derived from the array by deleting some elements without changing the order of the remaining elements. 
// Input
// The first line contains an integer n: the size of the array.
// After this there are n integers x_1,x_2,\ldots,x_n: the contents of the array.
// Output
// Print the length of the longest increasing subsequence.
// Constraints

// 1 \le n \le 2 \cdot 10^5
// 1 \le x_i \le 10^9

// Example
// Input:
// 8
// 7 3 5 3 6 2 9 8

// Output:
// 4
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i:arr) cin>>i;
    // cout<<f(n-1,INT_MAX,arr)<<endl;
    vector<vector<int>> dp(n+1,vector<int>(n+1,0)); //storing the index of value due to constraints 1e9
    for(int indx=1;indx<=n;indx++){ 
        for(int prev=1;prev<indx;prev++){
            dp[indx][prev]=dp[indx-1][prev];
            if(arr[prev-1]<arr[indx-1]){
                dp[indx][prev]=max(dp[indx][prev],1+dp[indx-1][indx]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

}