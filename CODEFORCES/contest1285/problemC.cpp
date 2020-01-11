;// problem link - https://codeforces.com/contest/1285/problem/C
#include<bits/stdc++.h>
using namespace std;
int main(){
long long x;
cin>>x;
vector<long long> pro;
for(int i=2;i<=sqrt(x);i++){

      if(x%i==0){
         long long a=1;
         while(x%i==0){
            a=a*i;
            x=x/i;
         }
        pro.push_back(a);
      }
}
if(x>1)
pro.push_back(x);
long long pr=pro.size(),ansa=1e14,ansb=1e14;
for(long long i=0;i< (1<<pr);i++){

    long long a=1,b=1;
    for(long long j=0;j<pr;j++){
        if(i&(1<<j))
           a=a*pro[j];
        else
          b=b*pro[j];
    }
    if(max(ansa,ansb)> max(a,b)){
        ansa=a;
        ansb=b;
    }

}
cout<<min(ansa,ansb)<<" "<<max(ansa,ansb)<<"\n";

}
