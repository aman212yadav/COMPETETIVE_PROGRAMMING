// problem link - https://leetcode.com/problems/valid-palindrome
class Solution {
public:
    // time complexity -O(N)
    // space complexity -O(1)
    bool isAlphanumeric(char c){
        if(c>='a' && c<='z' || c>='A' && c<='Z' || c>='0' && c<='9')
            return true;
        return false;
    }
    bool isPalindrome(string s) {
     int i=0,j=s.size()-1;

        while(i<j ){
            if(!isAlphanumeric(s[i]))
            {i++;
             continue;
            }
            if(!isAlphanumeric(s[j])){
                j--;
                continue;
            }
            if(std::tolower(s[i])!=std::tolower(s[j]))
                return false;
            i++;
            j--;
        }
        return true;
    }
};
