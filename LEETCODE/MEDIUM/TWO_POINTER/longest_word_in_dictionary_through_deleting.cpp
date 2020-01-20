// problem link -  https://leetcode.com/problems/longest-word-in-dictionary-through-deleting
// time complexity - O(n*x)

class Solution {
public:
    bool isSubsequence(string &s1,string &s2){
        int n=s1.size(),m=s2.size(),j=0;
        for(int i=0;i<m && j<n;i++){
            if(s2[i]==s1[j])
                j++;
        }
        return j==n;
    }
    string findLongestWord(string s, vector<string>& d) {
        int max_len=0;
        string ans;
        for(auto k : d){
            if(isSubsequence(k,s) )
            {
                if(k.size()>max_len){
                    max_len=k.size();
                    ans=k;
                }else if(k.size()==max_len && k < ans){
                    ans=k;
                }
            }
        }
        return ans;
    }
};
