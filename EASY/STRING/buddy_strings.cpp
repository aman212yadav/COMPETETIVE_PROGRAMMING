// problem link    - https://leetcode.com/problems/buddy-strings
// time complexity - O(n)
// space complexity - O(1)
class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.size()!=B.size())
            return false;
        int co=0,a=-1,b=-1;
        int brr[26]={0};
        bool bb=false;
        for(int i=0;i<A.size();i++){
            brr[B[i]-'a']++;
            if(brr[B[i]-'a']>1)
            {
                bb=true;
            }
            if(A[i]!=B[i]){
               if(a==-1){
                   a=i;
               }else{
                   b=i;
               }
                co++;
            }
        }
        if(co>2)
            return false;
        else if(co==2){
            if(A[b]==B[a] && A[a]==B[b])
                return true;
            return false;
        }
        else if(co==1){
            return false;
        }else{
            return bb;
        }
    }
};
