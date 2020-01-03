// problem link - https://leetcode.com/problems/number-of-segments-in-a-string/
// time complexity - O(n)
// space complexity - O(1)
class Solution {
public:
    int countSegments(string s) {
        int seg=0,i=0;
        while(i<s.size()){
               while(i < s.size() && s[i]==' '){
                   i++;
               }
              if(i<s.size()){
                  seg++;
              }
            while(i<s.size() && s[i]!=' '){
                i++;
            }
        }
        return seg;
    }
};
