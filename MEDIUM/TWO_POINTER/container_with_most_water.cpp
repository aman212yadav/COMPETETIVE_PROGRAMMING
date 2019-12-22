// problem link - https://leetcode.com/problems/container-with-most-water


// time complexity - O(N)
// space complexity - O(1)
class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size()<=1){
            return 0;
        }
        int ma=0,l=0,r=height.size()-1;
        while(l < r){
            int width=r-l;
            ma=max(ma,width*min(height[l],height[r]));
            if(height[l]<height[r]){
                l++;
            }else{
                r--;
            }
        }
        return ma;
    }
};
