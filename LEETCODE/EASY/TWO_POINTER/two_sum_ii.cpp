// problem link - https://leetcode.com/problems/two-sum-ii-input-array-is-sorted
class Solution {
public:
    // time complexity - O(n)
    // space complexity - O(n)
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> m;
        for(int i=0;i<numbers.size();i++){
            if(m[target-numbers[i]]){
                return {m[target-numbers[i]],i+1};
            }
            m[numbers[i]]=i+1;
        }
        return {};
    }
    // space complexity o(1)

     vector<int> twoSum(vector<int>& numbers, int target) {

        int l=0,r=numbers.size()-1;
        while(l<r){
            if(numbers[l]+numbers[r]==target){
                return {l+1,r+1};
            }else if( numbers[l]+numbers[r]>target){
                r--;
            }else{
              l++;
            }
        }
        return {};
    }

};
