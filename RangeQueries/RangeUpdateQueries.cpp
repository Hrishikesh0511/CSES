// Given an array of n integers, your task is to process q queries of the following types:

// increase each value in range [a,b] by u
// what is the value at position k?

// Input
// The first input line has two integers n and q: the number of values and queries.
// The second line has n integers x_1,x_2,\dots,x_n: the array values.
// Finally, there are q lines describing the queries. Each line has three integers: either "1 a b u" or "2 k".
// Output
// Print the result of each query of type 2.
// Constraints

// 1 \le n,q \le 2 \cdot 10^5
// 1 \le x_i, u \le 10^9
// 1 \le k \le n
// 1 \le a \le b \le n

// Example
// Input:
// 8 3
// 3 2 4 5 1 1 5 3
// 2 4
// 1 2 5 1
// 2 4

// Output:
// 5
// 6
//Note : Lazy propogation is an overkill for this question we can also do this question 
//using technique we use in presum 
// Process:
// whenever there is an update we do a point update on left with value(val) and right+1 with value (-(val))
// now whenever there is a query on indx k we just do a rangesumquery(0,k);=>  :)
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
class SegTree{
    public:
    vector<ll> seg,lazy;
        SegTree(int n){
        //constructor for initializing the seg tree with given size
        seg.resize(4*n,0);
        lazy.resize(4*n,0); //for lazy update in range updates
        }
        //build
        void build(int indx,int left,int right,vector<int> &arr){
            if(left==right){
                seg[indx]=arr[left];    
                return ;
            }
            int mid=(left+right)/2;
            build(2*indx+1,left,mid,arr);
            build(2*indx+2,mid+1,right,arr);
            seg[indx]=seg[2*indx+1]+seg[2*indx+2];  
        }
        //updateRange
        void updateRange(int indx,int left,int right,int ul,int ur,int value){
            //update the previous lazy updates if any
            if(lazy[indx]!=0){
                seg[indx]+=(right-left+1)*lazy[indx];
                 //propogate the update downwards if any children
                if(left!=right){
                    lazy[2*indx+1]+=lazy[indx];
                    lazy[2*indx+2]+=lazy[indx];
                }
                lazy[indx]=0;
            }
            //no overlap
            if(ul>right || ur<left){
                return ;
            }
            //completely overlapped inside
            else if(ul<=left && ur>=right){
                //update it 
                seg[indx]+=(right-left+1)*value;
                //propogate update downwards if there are any children
                if(left!=right){
                    lazy[2*indx+1]+=value;
                    lazy[2*indx+2]+=value;
                }
                return ;
            }
            //partial overlap
            else{
                int mid=(left+right)/2;
                updateRange(2*indx+1,left,mid,ul,ur,value);
                updateRange(2*indx+2,mid+1,right,ul,ur,value);
                seg[indx]=seg[2*indx+1]+seg[2*indx+2];
                return ;
            }

        }
        //query
        ll pointquery(int indx,int left,int right,int point){
            // update the previous lazy updates if any
            if (lazy[indx] != 0) {
                seg[indx] += (right - left + 1) * lazy[indx];
                // propogate the update downwards if any children
                if (left != right) {
                    lazy[2 * indx + 1] += lazy[indx];
                    lazy[2 * indx + 2] += lazy[indx];
                }
                lazy[indx] = 0;
            }
                if(left==right){
                return seg[indx];
            }
            int mid=(left+right)/2;
            if(point<=mid){
                return pointquery(2*indx+1,left,mid,point);
            }
            else{
                return pointquery(2*indx+2,mid+1,right,point);
            }
        }
};
int main(){
    int n,nq;
    cin>>n>>nq;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    SegTree* st=new SegTree(n);
    st->build(0,0,n-1,arr);
    while(nq--){
        int type;
        cin>>type;
        if(type==1){
            int ul,ur,val;
            cin>>ul>>ur>>val;
            st->updateRange(0,0,n-1,ul-1,ur-1,val);
        }
        else 
        {
            int k;
            cin>>k;
            cout<<st->pointquery(0,0,n-1,k-1)<<endl;
           
        }
    }
    return 0;
}

