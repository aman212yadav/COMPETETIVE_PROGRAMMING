#include<bits/stdc++.h>
using namespace std;
int main(){
long long t,n;
cin>>t;
while(t--){
    cin>>n;
    int co=0;
    unordered_map<long long ,bool> m;
    vector<long long> f;
    for(long long i=2;i*i<=n;i++){
        if(n%i==0 && !m[i]){


            if(co==2){
               if(n>1 && !m[n])
               {
                   m[n]=true;
                   f.push_back(n);
                   co++;
                   n=1;
               }
                break;
            }else{
            f.push_back(i);
            n=n/i;
            m[i]=true;
            co++;
            }

        }

    }
    if(n>1 && !m[n] && co<3){
        f.push_back(n);
    }
    if(f.size()==3){
        cout<<"YES\n";
        for(auto k : f)
            cout<<k<<" ";
        cout<<"\n";
    }else{
      cout<<"NO\n";
    }


}


}
