#include<bits/stdc++.h>
using namespace std;
int main(){
long long t,a,b,c,n,r;
cin>>t;
while(t--){
   cin>>a>>b>>c>>n;
   if((a+b+c+n)%3){
    cout<<"NO\n";
   }else{
     bool bb=true;
     r=(a+b+c+n)/3;
     if(r-a < 0 || r-b < 0 ||r-c<0)
       bb=false;
     if(bb)
     cout<<"YES\n";
     else
     cout<<"NO\n";


   }

}


}
