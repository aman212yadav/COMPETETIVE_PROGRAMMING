// problem link - https://leetcode.com/problems/maximum-subarray
// time complexity - O(N)
// space complexity - O(1)
class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int running_sum=0,max_so_far=0,n=arr.size(),ma=arr[0];
        for(int i=0;i<n;i++){
            ma=max(ma,arr[i]);
            running_sum+=arr[i];
            max_so_far=max(max_so_far,running_sum);
            if(running_sum<0){
                running_sum=0;
            }

        }
        return max_so_far==0?ma:max_so_far;
    }
};
