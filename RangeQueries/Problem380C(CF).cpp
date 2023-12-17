// C. Sereja and Brackets
// Sereja has a bracket sequence s1, s2, ..., sn, or, in other words, a string s of length n, consisting of characters "(" and ")".

// Sereja needs to answer m queries, each of them is described by two integers li, ri (1 ≤ li ≤ ri ≤ n). The answer to the i-th query is the length of the maximum correct bracket subsequence of sequence sli, sli + 1, ..., sri. Help Sereja answer all queries.

// You can find the definitions for a subsequence and a correct bracket sequence in the notes.
// Input

// The first line contains a sequence of characters s1, s2, ..., sn (1 ≤ n ≤ 106) without any spaces. Each character is either a "(" or a ")". The second line contains integer m (1 ≤ m ≤ 105) — the number of queries. Each of the next m lines contains a pair of integers. The i-th line contains integers li, ri (1 ≤ li ≤ ri ≤ n) — the description of the i-th query.
// Output

// Print the answer to each question on a single line. Print the answers in the order they go in the input.
// Examples
// Input

// ())(())(())(
// 7
// 1 1
// 2 3
// 1 2
// 1 12
// 8 12
// 5 11
// 2 10

// Output
// 0
// 0
// 2
// 10
// 4
// 6
#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int open;
    int close;
    int full;
    node(){
        open=0,close=0,full=0;
    }
};
vector<node*> seg;
void mergeNodes(node* res,node* left,node *right){
    res->open=left->open+right->open-min(left->open,right->close);
    res->close=left->close+right->close-min(left->open,right->close);
    res->full=left->full+right->full+min(left->open,right->close);
}
void build(int indx,int left,int right,string &s){
    if(left==right){
        if(s[left]=='('){
            seg[indx]->open=1;
            seg[indx]->close=0;
            seg[indx]->full=0;
        }
        else{
            seg[indx]->open=0;
            seg[indx]->close=1;
            seg[indx]->full=0;
        }
        return;
    }
    int mid=(left+right)/2;
    build(2*indx+1,left,mid,s);
    build(2*indx+2,mid+1,right,s);
    mergeNodes(seg[indx],seg[2*indx+1],seg[2*indx+2]);
}
node* query(int indx,int left,int right,int ql,int qr){
    if(ql>right || qr<left){
        return new node();
    }
    else if(ql<=left && qr>=right){
        return seg[indx];
    }
    else {
        int mid=(left+right)/2;
        node *temp=new node();
        mergeNodes(temp,query(2*indx+1,left,mid,ql,qr),query(2*indx+2,mid+1,right,ql,qr));
        return temp;
    }
}
int main(){
string s;
cin>>s;
int nq;
cin>>nq;
int n=s.size();
seg.resize(4*n);
for(int i=0;i<4*n;i++){
    seg[i]=new node();
}
//build the seg tree
build(0,0,n-1,s);

while(nq--){
    int ql,qr;
    cin>>ql>>qr;
    //as it is one indexed
    cout<<query(0,0,n-1,ql-1,qr-1)->full*2<<endl;
}
for(node *n:seg){
    delete n;
}
}