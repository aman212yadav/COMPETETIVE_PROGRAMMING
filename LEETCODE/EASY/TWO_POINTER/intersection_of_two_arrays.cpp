// problem link - https://leetcode.com/problems/intersection-of-two-arrays
// time complexity - O(nlogn)
// space complexity - O(n)
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int> v;
        int l1=0,l2=0;
        while(l1<nums1.size() && l2 < nums2.size()){
            if(nums1[l1]==nums2[l2]){

                v.push_back(nums1[l1]);
                int prev=nums1[l1];
                while( l1<nums1.size() && l2 < nums2.size() &&prev==nums1[l1]&& prev==nums2[l2] ){
                     l1++;
                    l2++;
                }
            }else if(nums1[l1]>nums2[l2]){
                l2++;
            }else{
                l1++;
            }

        }
        return v;
    }
};
