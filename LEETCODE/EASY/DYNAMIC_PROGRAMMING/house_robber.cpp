// problem link - https://leetcode.com/problems/house-robber
// time complexity - O(N)
// space complexity - O(N)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
       vector<int> dp(n+1);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            dp[i]=dp[i-1];
            dp[i]=max(dp[i],i-2>=0 ? dp[i-2]+nums[i-1]:nums[i-1]);
        }
        return dp[n];
    }
};
