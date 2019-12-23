// problem link - https://leetcode.com/problems/merge-sorted-array/
class Solution {
public:
    // time complexity  - O(n)
    // space complexity - O(n)
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0,j=0,co=0;
        vector<int> v(n+m);
        while(i<m && j <n){
            if(nums1[i]>=nums2[j]){
                v[co]=nums2[j];
                j++;
            }else{
                v[co]=nums1[i];
                i++;
            }
            co++;

        }
        while(j<n){
            v[co]=nums2[j];
            j++;
            co++;
            }
        while(i<m){
           v[co]=nums1[i];
            i++;
            co++;
        }
        for(int i=0;i<n+m;i++)
            nums1[i]=v[i];
    }
};
