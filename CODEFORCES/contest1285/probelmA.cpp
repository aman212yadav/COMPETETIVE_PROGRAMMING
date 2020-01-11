// problem link - https://codeforces.com/contest/1285/problem/A
#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
string s;
cin>>s;
int l=0,r=0;
for(auto k : s){
   if(k=='L')
   l++;
   else
   r++;
}
cout<<l+r+1<<"\n";


}
