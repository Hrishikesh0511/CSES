// There are n people who want to get to the top of a building which has only one elevator. You know the weight of each person and the maximum allowed weight in the elevator. What is the minimum number of elevator rides?
// Input
// The first input line has two integers n and x: the number of people and the maximum allowed weight in the elevator.
// The second line has n integers w_1,w_2,\dots,w_n: the weight of each person.
// Output
// Print one integer: the minimum number of rides.
// Constraints

// 1 \le n \le 20
// 1 \le x \le 10^9
// 1 \le w_i \le x

// Example
// Input:
// 4 10
// 4 8 6 1

// Output:
// 2
//Greedily finding out the sum and taking the ceil of division with weight fails when the weights are something like this 8 8 8 6 and 
// 10 max capacity our approach gives 3 but the actual answer is 4
//this can be solved in O(N!N) time by taking all the permutations and checking which one gives me minimum possible
//          
#include<bits/stdc++.h>
using namespace std;
// void f(int indx,vector<int> &weights,int w,vector<int> &vis){
//     if(indx==-1) return ;

// }
int main(){
    double n,w;
    cin>>n>>w;
    vector<int> weights(n);
    double sum=0;
    for(int i=0;i<n;i++){
        cin>>weights[i];
        sum+=weights[i];
    }
    cout<<ceil(sum/w)<<endl;
    // vector<int> vis(n,0);
    // f(n-1,weights,w,vis);
}