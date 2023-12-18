//this is alternative to range sum segment tree 
#include<bits/stdc++.h>
using namespace std;
class FenTree{
    vector<int> fen;
    public:
    FenTree(int n){
        fen.resize(n+1,0);
    }
    void update(int i,int val){
        int N=fen.size();
        while(i<N){
            fen[i]+=val;
            i+=(i&(-i));   //going to the next index where we need to update
        }
    }
    void build(vector<int> &arr){
        int n=arr.size();
        for(int i=0;i<n;i++){
            update(i+1,arr[i]);
        }
    }
    int rangesum(int i){
        int sum=0;
        while(i>0){
            sum+=fen[i];
            i-=(i&(-i));    //unsetting the rightmost set bit every time 
        }
        return sum;
    }
    int query(int left,int right){
        return rangesum(right+1)-rangesum(left);
    }
    int findLB(int val){
        //binary lifting
        int n=fen.size();
        int prevsum=0;
        int pos=0;
        for(int i=log2(n);i>=0;i--){
            if(prevsum+fen[pos+(1<<i)]<val){  //decide whether to give a lift or not
                prevsum+=fen[pos+(1<<i)];   
                pos+=(1<<i);                  //giving a lift to the pos
            }
        }
        return pos+1;
    }
};
int main(){
    int n,nq;
    cin>>n>>nq;
    vector<int> arr(n);
    FenTree* ft=new FenTree(n);
    for(auto &i:arr) cin>>i;
    ft->build(arr);
    while(nq--){
        int ql,qr;
        cin>>ql>>qr;
        cout<<ft->query(ql-1,qr-1)<<endl;
    }
    // cout<<ft->findLB(9)<<endl;
}