class Solution {
public:
     bool ispal(string s){
         int l=0,r=s.size()-1;
         while(l<r && s[l]==s[r]){
             l++;
             r--;
         }
         return l>=r;
     }
    int removePalindromeSub(string s) {
        if(s.size()==0)
            return 0;


        if(ispal(s))
            return 1;
        return 2;

    }
};
