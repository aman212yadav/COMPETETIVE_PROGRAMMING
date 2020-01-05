// problem link     - O(n)
// time complexity  - O(n)
// space complexity - O(1)
class Solution {
public:
    bool validPalindrome(string s) {
        int i1,j1,i=0,j=s.size()-1;
        while(i<j && s[i]==s[j]){
            i++;
            j--;
        }
        if(i>=j)
            return true;
        j1=j-1;
        i1=i;
        while(i1<j1 && s[i1]==s[j1]){
            i1++;
            j1--;
        }
        if(i1>=j1)
            return true;
        i1=i+1;
        j1=j;
        while(i1<j1 && s[i1]==s[j1]){
            i1++;
            j1--;
        }
        if(i1>=j1)
            return true;
        return false;
    }
};
