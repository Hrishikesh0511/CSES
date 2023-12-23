// You are given an integer n. On each step, you may subtract one of the digits from the number.
// How many steps are required to make the number equal to 0?
// Input
// The only input line has an integer n.
// Output
// Print one integer: the minimum number of steps.
// Constraints

// 1 \le n \le 10^6

// Example
// Input:
// 27

// Output:
// 5

// Explanation: An optimal solution is 27 \rightarrow 20 \rightarrow 18 \rightarrow 10 \rightarrow 9 \rightarrow 0
#include<bits/stdc++.h>
using namespace std;
#define mx 1e7
int f(int n){
    vector<int> dp(n+1,mx);
    dp[0]=0;
    for(int i=1;i<=n;i++){
    string num=to_string(i);
    for(int j=0;j<num.size();j++){
        if((num[j]-'0')>i) continue;
        dp[i]=min(dp[i],1+dp[i-(num[j]-'0')]);
    }
    }
    return dp[n];
}
int main(){
    int n;
    cin>>n;
    cout<<f(n)<<endl;
}