// problem link     - https://leetcode.com/problems/single-number
// time complexity  - O(n)
// space complexity - O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(auto k : nums)
             ans=ans^k;
        return ans;
    }
};
