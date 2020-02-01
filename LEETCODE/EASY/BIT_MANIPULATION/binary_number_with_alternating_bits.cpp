// problem link     - https://leetcode.com/problems/binary-number-with-alternating-bits
// time complexity  - O(log(n))
// space complexity - O(1)
class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool prev=n&1;
        while(n && (n&1)==prev){
            prev=!prev;
            n=n/2;
        }
        return n==0;
    }
};
