#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
vector<vector<ll>> mulitply(vector<vector<ll>> mat1,vector<vector<ll>> mat2){
    int n1=mat1.size(),n2=mat2.size();
    int m1=mat1[0].size(),m2=mat2[0].size();
    vector<vector<ll>> res(n1,vector<ll> (m2));
    for(int i=0;i<n1;i++){
        for(int j=0;j<m1;j++){
            ll sum=0;
            for(int k=0;k<m2;k++){
                sum=(sum+(mat1[i][k]*mat2[k][j])%mod)%mod;
            }
            res[i][j]=sum;
        }
    }
    return res;
}
vector<vector<ll>> power(vector<vector<ll>> mat,int n){
    if(n==1) return mat;
    vector<vector<ll>>cur = power(mat,n/2);
    if(n%2==0){
        return mulitply(cur,cur);
    }
    else{
        return mulitply(mat,mulitply(cur,cur));
    }
}
int main(){
    int n;
    cin>>n;
    if(n<=2){
        cout<<(n!=0);
        return 0;
    }
    vector<vector<ll>> arr{{1,1},{1,0}};
    vector<vector<ll>> res=power(arr,n-2);
    cout<<res[0][0];
}
