// problem link -https://codeforces.com/contest/1285/problem/B
#include<bits/stdc++.h>
using namespace std;
int main(){
int t,n;
cin>>t;
while(t--){

    cin>>n;
    long long  arr[n],su=0;
    for(int i=0;i<n;i++)
        {cin>>arr[i];
        su+=arr[i];
        }
        long long lpre=0,rpre=0,ma=-1e15,rsu=0,tprev=0;
        for(int i=0;i<n;i++){
            rsu+=arr[i];
            if(rsu>ma){
                ma=rsu;
                lpre=tprev;
                rpre=i;
            }
            if(rsu<=0){
                rsu=0;
                tprev=i+1;
            }


        }
        if(lpre==0 && rpre==n-1){
            cout<<"YES\n";
        }else if(su>ma){
        cout<<"YES\n";
        }else{
        cout<<"NO\n";
        }
