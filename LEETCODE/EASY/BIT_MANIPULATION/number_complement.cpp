// problem link - https://leetcode.com/problems/number-complement
// time complexity - O(1)
// space complexity - O(1)
class Solution {
public:
    int findComplement(int num) {
       long ans=0,two=1;
        while(num){
            ans=ans+(!(num%2))*two;
            two=two*2;
            num=num>>1;
        }
        return ans;
    }
};
