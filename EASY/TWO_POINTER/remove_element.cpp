// problem link - https://leetcode.com/problems/remove-element


 class Solution {
public:

    //  time complexity - O(n)
    // space complexity - O(1)
    int removeElement(vector<int>& nums, int val) {
        if(nums.size()==0)
            return 0;
        int l=0,r;
        while(l<nums.size() && nums[l]!=val){
            l++;
        }
        r=l+1;
        while(r<nums.size()){
            if(nums[r]!=val){
                nums[l]=nums[r];
                l++;
            }
            r++;
        }
        return l;
    }
};

