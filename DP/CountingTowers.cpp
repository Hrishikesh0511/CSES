// Your task is to build a tower whose width is 2 and height is n. You have an unlimited supply of blocks whose width and height are integers.


// Given n, how many different towers can you build? Mirrored and rotated towers are counted separately if they look different.
// Input
// The first input line contains an integer t: the number of tests.
// After this, there are t lines, and each line contains an integer n: the height of the tower.
// Output
// For each test, print the number of towers modulo 10^9+7.
// Constraints

// 1 \le t \le 100
// 1 \le n \le 10^6

// Example
// Input:
// 3
// 2
// 6
// 1337

// Output:
// 8
// 2864
// 640403945
//Approach:
//For n=1 => we had two choices either to keep .. 2 blocks of width 1 in a row or __ 1 block of width 2
//Now for n=2 => in previous let us assume we had chosen 2 blocks => then we had 3 choices 
//1)to extend both of them =>in this we had only one choice by extending both (dp[i-1][0])
//2)extend either of them => in this we had two choices either to extend left one or right one (2*dp[i-1][0])
//3)do not extend at all =>  in this we had two choices either to put 2 width block or 1 width 2 blocks(dp[i-1][0]+dp[i-1][1])
//If we assume previous is one block 2 width then we had two choices
//1)To extend (dp[i-1][1])
//2)To not extend=>2 choices (dp[i-1][1]+dp[i-1][0])
#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    ll dp[1000005][2];
    dp[1][0]=1;
    dp[1][1]=1;
    //calculating before only
    for(int i=2;i<=1000000;i++){
        dp[i][0]=((4*dp[i-1][0])%mod+dp[i-1][1])%mod;
        dp[i][1]=((2*dp[i-1][1])%mod+dp[i-1][0])%mod;
    }
    while(t--){
        int n;
        cin>>n;   
        cout<<(dp[n][0]+dp[n][1])%mod<<"\n";
    }
}