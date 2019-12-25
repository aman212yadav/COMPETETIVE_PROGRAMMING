// problem link - https://leetcode.com/problems/partition-array-for-maximum-sum
class Solution {
public:
    // time complexity - O(n*K)
    // space complexity - O(n)
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        vector<int> dp(A.size(),0);
        for(int i=0;i<A.size();i++){
            int ma=A[i];
            for(int j=0;j<K;j++){
                if(i-j>=0){
                     ma=max(ma,A[i-j]);
                    int su=(j+1)*ma;
                    if(i-j-1>=0)
                        su+=dp[i-j-1];
                    dp[i]=max(dp[i],su);
                }
            }

        }
        return dp[A.size()-1];
    }
};
