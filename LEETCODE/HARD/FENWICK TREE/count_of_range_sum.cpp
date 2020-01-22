// problem link - https://leetcode.com/problems/count-of-range-sum
// time complexity - O(nlog(n)^2)
// space com-plexity - O(n)
class Solution {
public:
    int solution(vector<int> &nums,int l,int r,int lower,int upper){
        if(l>r)
            return 0;
        if(l==r){
            return nums[l]>=lower && nums[l]<=upper;
        }
        int m=(l+r)/2;
        long long sum=0;
        vector<long long> pre;
        for(int i=m+1;i<=r;i++){
            sum+=nums[i];
            pre.push_back(sum);
        }
        sort(pre.begin(),pre.end());
        sum=0;
        int ans=0;
        for(int i=m;i>=l;i--){
            sum+=nums[i];
            int lidx=lower_bound(pre.begin(),pre.end(),lower-sum)-pre.begin();
            int uidx=upper_bound(pre.begin(),pre.end(),upper-sum)-pre.begin();
            ans+=(uidx-lidx);
        }
        ans+=solution(nums,l,m,lower,upper);
        ans+=solution(nums,m+1,r,lower,upper);
        return ans;
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if( nums.size()==0 || lower>upper )
            return 0;
       return  solution(nums,0,nums.size()-1,lower,upper);
        
    }
};
