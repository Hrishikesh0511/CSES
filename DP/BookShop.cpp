// You are in a book shop which sells n different books. You know the price and number of pages of each book.
// You have decided that the total price of your purchases will be at most x. What is the maximum number of pages you can buy? You can buy each book at most once.
// Input
// The first input line contains two integers n and x: the number of books and the maximum total price.
// The next line contains n integers h_1,h_2,\ldots,h_n: the price of each book.
// The last line contains n integers s_1,s_2,\ldots,s_n: the number of pages of each book.
// Output
// Print one integer: the maximum number of pages.
// Constraints

// 1 \le n \le 1000
// 1 \le x \le 10^5
// 1 \le h_i, s_i \le 1000

// Example
// Input:
// 4 10
// 4 8 5 3
// 5 12 8 1

// Output:
// 13

// Explanation: You can buy books 1 and 3. Their price is 4+5=9 and the number of pages is 5+8=13.
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,limit;
    cin>>n>>limit;
    vector<int> pages(n),prices(n);
    for(auto &i:prices) cin>>i;
    for(auto &i:pages) cin>>i;
    vector<vector<int>> dp(n+1,vector<int> (limit+1,INT_MIN));
    //basecase indx==0
    for(int i=0;i<=limit;i++){
        dp[0][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=limit;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=prices[i-1]){
                dp[i][j]=max(dp[i][j],pages[i-1]+dp[i-1][j-prices[i-1]]);
            }
        }
    }
    cout<<dp[n][limit]<<endl;

}