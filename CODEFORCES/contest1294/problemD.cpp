#include<bits/stdc++.h>
using namespace std;
int main(){
  long long q,x,k;
  cin>>q>>x;
  long long arr[x];
  set<long long > s;
  for(int i=0;i<x;i++)
  s.insert(i),arr[i]=i;
  while(q--){
     cin>>k;
     long long  c=arr[k%x];
     s.erase(s.find(c));
     arr[k%x]=c+x;
     s.insert(c+x);
     cout<<*s.begin()<<"\n";
  }

}
