/*Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to calculate the number of distinct ordered ways you can produce a money sum x using the available coins.
For example, if the coins are \{2,3,5\} and the desired sum is 9, there are 3 ways:

2+2+5
3+3+3
2+2+2+3

Input
The first input line has two integers n and x: the number of coins and the desired sum of money.
The second line has n distinct integers c_1,c_2,\dots,c_n: the value of each coin.
Output
Print one integer: the number of ways modulo 10^9+7.
Constraints

1 \le n \le 100
1 \le x \le 10^6
1 \le c_i \le 10^6

Example
Input:
3 9
2 3 5

Output:
3
*/
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int main(){
    int n,target;
    cin>>n>>target;
    vector<int> arr(n);
    for(auto &i:arr) cin>>i;
    vector<ll> dp(target+1,0);
    dp[0]=1;
    for(int indx=1;indx<=n;indx++){
        for(int j=0;j<=target;j++){
            if(j>=arr[indx-1]){
                dp[j]=(dp[j]+dp[j-arr[indx-1]])%mod;
            }
        }
    }
    cout<<dp[target]<<endl;
}