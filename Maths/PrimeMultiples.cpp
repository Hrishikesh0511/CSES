#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll n,k;
    cin>>n>>k;
    ll arr[k];
    for(int i=0;i<k;i++){
        cin>>arr[i];
    }
    ll s=pow(2,k);
    int sum=0;
    for(int i=1;i<s;i++){
        int bits=0;
        ll curr=1;
        for(int j=0;j<k;j++){
                if(i & (1<<j)){
                bits++;
                curr*=arr[j];
                }
            }
            curr=n/curr;
            if(bits%2==1){
                sum+=curr;
            }
            else{
                sum-=curr;
            }   
    }
    cout<<sum;
}