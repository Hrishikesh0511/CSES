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
        //RangeUpdate
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
        //point update
        void updatePoint(int indx,int left,int right,int point,int value){
            if(left==right){    //if both the ends are equal then we know that we reached the point so update the value
                seg[indx]=value;
                return ;
            }
            int mid=(left+right)/2;
            if(point<=mid){
                updatePoint(2*indx+1,left,mid,point,value);
            }
            else{
                updatePoint(2*indx+2,mid+1,right,point,value);
            }
            //after reaching thet index update the segments accordingly
            seg[indx]=seg[2*indx+1]+seg[2*indx+2];
        }
        //query
        ll pointQuery(int indx,int left,int right,int point){
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
                return pointQuery(2*indx+1,left,mid,point);
            }
            else{
                return pointQuery(2*indx+2,mid+1,right,point);
            }
        }
        //rangeQuery
        ll rangeQuery(int indx,int left,int right,int ql,int qr){
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
                return rangeQuery(2*indx+1,left,mid,ql,qr)+rangeQuery(2*indx+2,mid+1,right,ql,qr);
            }
        }
};