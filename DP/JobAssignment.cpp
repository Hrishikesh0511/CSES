// Problem Statement

// Let there be N workers and N jobs. Any worker can be assigned to perform any job, incurring some cost that may vary depending on the work-job assignment. It is required to perform all jobs by assigning exactly one worker to each job and exactly one job to each agent in such a way that the total cost of the assignment is minimized.

// Input Format
// Number of workers and job: N
// Cost matrix C with dimension N*N where C(i,j) is the cost incurred on assigning ith Person to jth Job.

// Sample Input
// 4

// [
// 9 2 7 8
// 6 4 3 7
// 5 8 1 8
// 7 6 9 4
// ]

// Sample Output
// 13

// Constraints
// N <= 20

#include<bits/stdc++.h>
using namespace std;
int mincost(int jobnum,int availpersons,vector<vector<int>> &arr,vector<vector<int>> &dp){
    if(jobnum==arr.size()){
        return 0;
    }
    if(dp[jobnum][availpersons]!=-1) return dp[jobnum][availpersons];
    int cost=INT_MAX;
    for(int i=0;i<arr.size();i++){
        if(availpersons &(1<<i)){   //if the person is available
            cost=min(cost,arr[i][jobnum]+mincost(jobnum+1,availpersons^(1<<i),arr,dp));
        }
    }
    return dp[jobnum][availpersons]=cost;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> arr(n,vector<int> (n)) ;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    vector<vector<int>> dp(n,vector<int>((1<<n),-1));
    //this represents that 0 th job and I had all n persons available to assign
    cout<<mincost(0,(1<<n)-1,arr,dp)<<endl;
}