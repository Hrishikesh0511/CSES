// You are given a list consisting of n integers. Your task is to remove elements from the list at given positions, and report the removed elements.
// Input
// The first input line has an integer n: the initial size of the list. During the process, the elements are numbered 1,2,\dots,k where k is the current size of the list.
// The second line has n integers x_1,x_2,\dots,x_n: the contents of the list.
// The last line has n integers p_1,p_2,\dots,p_n: the positions of the elements to be removed.
// Output
// Print the elements in the order they are removed.
// Constraints

// 1 \le n \le 2 \cdot 10^5
// 1 \le x_i \le 10^9
// 1 \le p_i \le n-i+1

// Example
// Input:
// 5
// 2 6 1 4 2
// 3 1 3 1 1

// Output:
// 1 2 2 6 4

// Explanation: The contents of the list are [2,6,1,4,2], [2,6,4,2], [6,4,2], [6,4], [4] and [].
//Idea is to initialize a list with all 1's where 1-> present 0->not present
//Now I will store the segment sum in the nodes based on the new array so whenever you need to remove an element 
//I 'll go to the element by comparing the segment nodes and make it zero and return the corresponding element in the array
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
void build(int indx,int left,int right,vector<int> &arr,vector<ll> &seg){
    if(left==right){
        seg[indx]=1;
        return ;
    }
    int mid=(left+right)/2;
    //go to the child nodes
    build(2*indx+1,left,mid,arr,seg);   //left child
    build(2*indx+2,mid+1,right,arr,seg);    //right child
    //The current segment value will be the sum of it's two childs
    seg[indx]=seg[2*indx+1]+seg[2*indx+2];
}
void query(int indx,int left,int right,int pos,vector<int> &arr,vector<ll> &seg){
    if(left==right){
        seg[indx]=0;    
        cout<<arr[right]<<" ";
        return ;
    }
    int mid=(left+right)/2;
    if(seg[indx]==pos){
        //whenever it is equal I'll make the pos such that it is always 
        //greater than seg[indx] so it will always go to the right till it reaches the point
        pos=INT_MAX;
    }
    if(seg[indx]>pos){
        query(2*indx+1,left,mid,pos,arr,seg);
    }
    if(seg[indx]<pos){
        query(2*indx+2,mid+1,right,pos,arr,seg);
    }
    seg[indx]=seg[2*indx+1]+seg[2*indx+2];
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<ll> seg(4*n,0);
    build(0,0,n-1,arr,seg);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        query(0,0,n-1,x,arr,seg);
    }
    cout<<endl;
    for(int i=0;i<4*n;i++){
        cout<<seg[i]<<" ";
    }
}
