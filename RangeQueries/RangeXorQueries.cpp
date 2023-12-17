// Given an array of n integers, your task is to process q queries of the form: what is the xor sum of values in range [a,b]?
// Input
// The first input line has two integers n and q: the number of values and queries.
// The second line has n integers x_1,x_2,\dots,x_n: the array values.
// Finally, there are q lines describing the queries. Each line has two integers a and b: what is the xor sum of values in range [a,b]?
// Output
// Print the result of each query.
// Constraints

// 1 \le n,q \le 2 \cdot 10^5
// 1 \le x_i \le 10^9
// 1 \le a \le b \le n

// Example
// Input:
// 8 4
// 3 2 4 5 1 1 5 3
// 2 4
// 5 6
// 1 8
// 3 3

// Output:
// 3
// 0
// 6
// 4
#include<bits/stdc++.h>
using namespace std;
#define ll long long
void build(int indx,int left,int right,vector<int> &arr,vector<ll> &seg){
    if(left==right){
        seg[indx]=arr[left];
        return;
    }
    int mid=(left+right)/2;
    build(2*indx+1,left,mid,arr,seg);
    build(2*indx+2,mid+1,right,arr,seg);
    seg[indx]=seg[2*indx+1]^seg[2*indx+2];
}
int query(int indx,int left,int right,int ql,int qr,vector<int> &arr,vector<ll> &seg){
    if(ql>right || qr<left)
    {
        return 0;
    }
    else if(ql<=left && qr>=right){
        return seg[indx];
    }
    else{
        int mid=(left+right)/2;
        return query(2*indx+1,left,mid,ql,qr,arr,seg)^query(2*indx+2,mid+1,right,ql,qr,arr,seg);
    }
}
int main(){
    int n,nq;
    cin>>n>>nq;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<ll> seg(4*n,0);
    //build the seg tree
    build(0,0,n-1,arr,seg);
    while(nq--){
        int ql,qr;
        cin>>ql>>qr;
        //as it is one indexed
        cout<<query(0,0,n-1,ql-1,qr-1,arr,seg)<<endl;
    }
}