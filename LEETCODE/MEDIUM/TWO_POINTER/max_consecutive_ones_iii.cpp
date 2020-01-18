//problem link - https://leetcode.com/problems/max-consecutive-ones-iii
// time complexity - O(n)
// space complexity - O(1)
class Solution {
public:
    int longestOnes(vector<int>& A, int k) {
        int ma=0,n=A.size();
        int l=0,r=0,zero=0;
        while(r<n){
            if(A[r]==0){
                zero++;
            }
            if(zero<=k){
                ma=max(r-l+1,ma);
            }
            while(zero>k){
                if(A[l]==0)
                    zero--;
                l++;
            }
            r++;
        }

        return ma;

    }
};
