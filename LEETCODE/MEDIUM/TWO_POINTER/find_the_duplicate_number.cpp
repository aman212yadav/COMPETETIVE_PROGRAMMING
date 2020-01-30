// problem link - https://leetcode.com/problems/find-the-duplicate-number
// time complexity - O(n)
// space complexity - O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int> s;
        int tortoise=0,rabbit=0;
        do{
            tortoise=nums[tortoise];
            rabbit=nums[nums[rabbit]];
        }while(tortoise!=rabbit);
        int ptr1=0,ptr2=tortoise;
        while(ptr1!=ptr2){
            ptr1=nums[ptr1];
            ptr2=nums[ptr2];
        }
        return ptr1;

    }
};
