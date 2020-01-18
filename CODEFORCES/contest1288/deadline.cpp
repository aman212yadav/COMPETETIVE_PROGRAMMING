#include<bits/stdc++.h>
using namespace std;
int main(){
long long t,n,d;
cin>>t;
while(t--){
     cin>>n>>d;
     if(n>=d){
       cout<<"YES\n";
     }
     else{
       bool b=false;
       long long x=1,prev=d;
       while(true){

           long long a=d/(x+1);
           if(d%(x+1))
               a++;
           if(prev<x+a)
               break;
           // cout<<x+a<<" "<<x<<" "<<a<<"\n";
            if(x+a<=n)
            {b=true;
             break;
            }
            prev=x+a;
             x++;

       }
     if(b)
     cout<<"YES\n";
     else
     cout<<"NO\n";

     }



}


}
