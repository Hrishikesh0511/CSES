// Given an array of n integers, your task is to process q queries of the following types:

// update the value at position k to u
// what is the sum of values in range [a,b]?

// Input
// The first input line has two integers n and q: the number of values and queries.
// The second line has n integers x_1,x_2,\dots,x_n: the array values.
// Finally, there are q lines describing the queries. Each line has three integers: either "1 k u" or "2 a b".
// Output
// Print the result of each query of type 2.
// Constraints

// 1 \le n,q \le 2 \cdot 10^5
// 1 \le x_i, u \le 10^9
// 1 \le k \le n
// 1 \le a \le b \le n

// Example
// Input:
// 8 4
// 3 2 4 5 1 1 5 3
// 2 1 4
// 2 5 6
// 1 3 1
// 2 1 4

// Output:
// 14
// 2
// 11
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
void build(int indx,int left,int right,vector<int> &arr,vector<ll> &seg){
    if(left==right){
        seg[indx]=arr[left];
        return ;
    }
    int mid=(left+right)/2;
    //go to the child nodes
    build(2*indx+1,left,mid,arr,seg);   //left child
    build(2*indx+2,mid+1,right,arr,seg);    //right child
    //The current segment value will be the sum of it's two childs
    seg[indx]=seg[2*indx+1]+seg[2*indx+2];
}
ll query(int indx,int left,int right,int ql,int qr,vector<int> &arr,vector<ll> &seg){
    //if the current segment is partially overlapping inside the query range
    //go to the left and right and update the value
    //if the current segment is fully inside the query range return the current seg value
    //if the current segment is fully out of the query range so the segment is not contributing to the query so make it negligible
    if((ql>right) || qr<left ){        //no overlap
        return 0;
    }
    else if(ql<=left && qr>=right){ //completely inside
        return seg[indx];
    }
    else{                           //partially overlap
        int mid=(left+right)/2;
        return query(2*indx+1,left,mid,ql,qr,arr,seg)+query(2*indx+2,mid+1,right,ql,qr,arr,seg);
    }
}
//point update
void update(int indx,int left,int right,int point,int value,vector<ll>& seg){
    if(left==right){    //if both the ends are equal then we know that we reached the point so update the value
        seg[indx]=value;
        return ;
    }
    int mid=(left+right)/2;
    if(point<=mid){
        update(2*indx+1,left,mid,point,value,seg);
    }
    else{
        update(2*indx+2,mid+1,right,point,value,seg);
    }
    //after reaching thet index update the segments accordingly
    seg[indx]=seg[2*indx+1]+seg[2*indx+2];
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
    int op,ql,qr;
    cin>>op>>ql>>qr;
    //as it is one indexed
    if(op==1)
    update(0,0,n-1,ql-1,qr,seg);
    if(op==2)
    cout<<query(0,0,n-1,ql-1,qr-1,arr,seg)<<endl;
}
}