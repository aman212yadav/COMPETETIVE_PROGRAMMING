// problem link - https://leetcode.com/problems/repeated-substring-pattern
// time complexity - O(n)
// space complexity - O(n)
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        vector<int> dp(s.size(),0);
        int j=0,i=1;
        while(i<s.size()){
            if(s[i]==s[j]){
                dp[i]=j+1;
                j++;
                i++;
            }else if(j==0){
                dp[i]=0;
               i++; 
            }else{
                j=dp[j-1];
            }
        }
        return dp[s.size()-1]&&dp[s.size()-1]%(s.size()-dp[s.size()-1])==0;
    }
};
