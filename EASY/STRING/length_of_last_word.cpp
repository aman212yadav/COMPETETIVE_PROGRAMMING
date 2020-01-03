// problem link     - https://leetcode.com/problems/length-of-last-word
// time complexity  - O(n)
// space complexity - O(1)
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len=0,tail=s.size()-1;
        while(tail>=0 && s[tail]==' '){
            tail--;
        }
        while(tail>=0 && s[tail]!=' '){
            tail--;
            len++;
        }
        return len;
    }
};
