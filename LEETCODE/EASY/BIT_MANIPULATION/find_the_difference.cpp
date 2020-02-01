// problem link     - https://leetcode.com/problems/find-the-difference
// time complexity  - o(n)
// space complexity - o(1)
class Solution {
public:
    char findTheDifference(string s, string t) {
        char r=0;
        for(auto k:s)
            r=r^k;
        for(auto k:t)
            r=r^k;
        return r;

    }
};
