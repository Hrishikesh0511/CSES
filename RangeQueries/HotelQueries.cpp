// There are n hotels on a street. For each hotel you know the number of free rooms. Your task is to assign hotel rooms for groups of tourists. All members of a group want to stay in the same hotel.
// The groups will come to you one after another, and you know for each group the number of rooms it requires. You always assign a group to the first hotel having enough rooms. After this, the number of free rooms in the hotel decreases.
// Input
// The first input line contains two integers n and m: the number of hotels and the number of groups. The hotels are numbered 1,2,\ldots,n.
// The next line contains n integers h_1,h_2,\ldots,h_n: the number of free rooms in each hotel.
// The last line contains m integers r_1,r_2,\ldots,r_m: the number of rooms each group requires.
// Output
// Print the assigned hotel for each group. If a group cannot be assigned a hotel, print 0 instead.
// Constraints

// 1 \le n,m \le 2 \cdot 10^5
// 1 \le h_i \le 10^9
// 1 \le r_i \le 10^9

// Example
// Input:
// 8 5
// 3 2 4 1 5 5 2 6
// 4 4 7 1 1

// Output:
// 3 5 0 1 1

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
    seg[indx]=max(seg[2*indx+1],seg[2*indx+2]);
}
void query(int indx,int left,int right,int val,vector<ll> &seg){
    //we reached the point 
    if(left==right){
        if(seg[indx]>=val){
            seg[indx]=seg[indx]-val;
            cout<<left+1<<" ";
        }
        return;
    }
    int mid=(left+right)/2;
    //we will only go to the right if going to left is of no use then it assures that it will always gives the first value that is greater
    if(seg[2*indx+1]>=val){
     query(2*indx+1,left,mid,val,seg);
    }
    else{
     query(2*indx+2,mid+1,right,val,seg);
    }
    seg[indx]=max(seg[2*indx+1],seg[2*indx+2]);
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<ll> seg(4*n,0);
    build(0,0,n-1,arr,seg);
    while(m--){
        int val;
        cin>>val;
        if(seg[0]<val) cout<<0<<" ";
        query(0,0,n-1,val,seg);
    }
}