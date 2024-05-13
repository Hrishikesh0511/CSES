    #include<bits/stdc++.h>
    using namespace std;
    bool isVowel(char a){
        return a=='a' or a=='e';
    } 
    int main(){
        int t;
        cin>>t;
        while(t--){
            int n;
            cin>>n;
            int arr[n];
            for(int i=0;i<n;i++){
                cin>>arr[i];
            }
            unordered_map<int,int> mp;
            bool flag=0;
            int sum=0;
            mp[0]++;
            for(int i=0;i<n;i++){
                if(i%2==0){
                    sum+=arr[i];
                    if(mp.find(sum)!=mp.end()) {
                    cout<<"YES"<<endl;
                    flag=1;
                    break;
                }
                }
                else{
                    sum-=arr[i];
                    if(mp.find(-1*sum)!=mp.end()) {
                    cout<<"YES"<<endl;
                    flag=1;
                    break;
                }
                }
                
                mp[sum]++;
            }
            if(!flag)
            cout<<"NO"<<endl;
        }
    }