// problem link - https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution {
public:
   //  time complexity - O(N)
   // space complexity - O(1)
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int l=0,r=0;
        while(r<nums.size()){
            if(nums[r]!=nums[l])
            {nums[l+1]=nums[r];
             l++;
            }
            r++;
        }
        return l+1;
    }
};
