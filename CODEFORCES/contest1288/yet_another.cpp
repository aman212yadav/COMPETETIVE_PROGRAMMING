#include<bits/stdc++.h>
using namespace std;
int no(int a){
    int c=0;
    while(a>0)
        {a=a/10;
        c++;
        }
        return c;
}
int main(){
long long t,A,B,b;
cin>>t;
while(t--){
   cin>>A>>B;
   long long ans=0,co=10;
   long long p=10;
   while(co--){
        if( p-1<=B ){
            ans++;
            }
            p=p*10;

   }
   cout<<ans*A<<"\n";

}



}
