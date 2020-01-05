// problem link - https://leetcode.com/problems/longest-substring-without-repeating-characters

//time complexity - O(n)
// space complexity - O(max_no_of_characters)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)
            return 0;
        int arr[256]={0};
        for(int i=0;i<256;i++)
             arr[i]=-1;
        int ma=1,cur=0;
        for(int i=0;i<s.size();i++){
            if(arr[s[i]]==-1 || arr[s[i]]< (i-cur)){
                cur++;
                ma=max(ma,cur);
            }else {
                cur=i-arr[s[i]];
                ma=max(ma,cur);
            }
               arr[s[i]]=i;
        }
               return ma;

    }

};
