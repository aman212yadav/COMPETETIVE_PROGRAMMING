// problem link - https://leetcode.com/problems/count-number-of-nice-subarrays
// time complexity - O(n)
// space complexity - O(1)
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int ans=0,acc=0;
        m[0]=1;
        for(int i=0;i<nums.size();i++){
            acc+=nums[i]%2;
            ans+=m[acc-k];
            m[acc]++;
        }
        return ans;
    }
};
