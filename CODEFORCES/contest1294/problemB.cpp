#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> p1,pair<int,int> p2){
      if(p1.first == p2.first){
         return p1.second < p2.second;
      }
      return p1.first < p2.first;
}
int main(){
long long t,n;
cin>>t;
while(t--){
    cin>>n;
    vector< pair<int,int> > p(n);
    for(int i=0;i<n;i++){
       cin>>p[i].first>>p[i].second;
    }
    sort(p.begin(),p.end(),cmp);
    string s="";
    bool b=true;
    pair<int,int>  prev={0,0};
    int i;
    for(i=0;i<n;i++){
        if(p[i].first<prev.first )
           {b=false;
           break;
           }
         if(p[i].second < prev.second){
            b=false;
            break;
         }
         int cx=p[i].first-prev.first;
         int cy=p[i].second-prev.second;
         for(int j=0;j<cx;j++)
              s+="R";
         for(int j=0;j<cy;j++)
              s+="U";
        prev=p[i];
    }
    if(!b)
    cout<<"NO\n";
    else{
     cout<<"YES\n";
     cout<<s<<"\n";
    }
