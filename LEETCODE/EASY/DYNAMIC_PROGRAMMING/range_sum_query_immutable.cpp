// problem link - https://leetcode.com/problems/range-sum-query-immutable/
// time compelxity - O(1) for query and O(N) for preprocessing
// space complexity - O(N)
class NumArray {
public:
    vector<int> sums;
    NumArray(vector<int>& nums) {
        sums=nums;
        for(int i=1;i<sums.size();i++)
            sums[i]+=sums[i-1];
    }

    int sumRange(int i, int j) {
        if(i)
            return sums[j]-sums[i-1];
        return sums[j];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
