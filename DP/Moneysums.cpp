// You have n coins with certain values. Your task is to find all money sums you can create using these coins.
// Input
// The first input line has an integer n: the number of coins.
// The next line has n integers x_1,x_2,\dots,x_n: the values of the coins.
// Output
// First print an integer k: the number of distinct money sums. After this, print all possible sums in increasing order.
// Constraints

// 1 \le n \le 100
// 1 \le x_i \le 1000

// Example
// Input:
// 4
// 4 2 5 2

// Output:
// 9
// 2 4 5 6 7 8 9 11 13

#include<bits/stdc++.h>
using namespace std;
void moneySums(int indx,int sum,vector<int> &arr,set<int> &st,vector<vector<int>> &dp){
    //base case
    if(indx==-1){
        if(sum==0) return ;
        st.insert(sum);
        return;
    }
    if(dp[indx][sum]!=-1) return ;
    //if already seen this sum at that index don't go ahead 
    dp[indx][sum]=0;
    //take
    moneySums(indx-1,sum+arr[indx],arr,st,dp);
    //not take
    moneySums(indx-1,sum,arr,st,dp);
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    set<int> st;
    vector<vector<int>> dp(n,vector<int> (1000000,-1));
    moneySums(n-1,0,arr,st,dp);
    cout<<st.size()<<endl;
    for(auto it:st){
        cout<<it<<" ";
    }
    return 0;
}