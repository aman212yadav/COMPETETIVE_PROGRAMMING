// problem link     - https://leetcode.com/problems/majority-element
// time complexity  - o(n)
// space complexity - o(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0,candidate;
        for(auto k : nums){
            if(count==0){
                count++;
                candidate=k;
            }else if(candidate==k){
                count++;
            }else{
                count--;
            }
        }
        count=0;
        for(auto k : nums){
            count+=(k==candidate);
        }
        if(count>nums.size()/2)
            return candidate;
        return -1;
    }
};
