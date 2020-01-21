// problem link - https://leetcode.com/problems/range-sum-query-mutable
// query - O(log(n))
// update - O(log(n))
class NumArray {
    vector<int> bit,num;
    int n;
public:
    NumArray(vector<int>& nums) {
        n=nums.size();
        bit.resize(n+1);
        num.resize(n);
        for(int i=0;i<n;i++)
            bit[i]=0,num[i]=0;
         bit[n]=0;
        for(int i=0;i<n;i++)
            update(i,nums[i]);


    }

    void update(int i, int val) {
        int prev=num[i];
        num[i]=val;
        val=val-prev;
        i++;
        while(i<=n){
            bit[i]+=val;
            i+=(i&(-i));
        }

    }
    int query(int idx){
        idx++;
        int ans=0;
        while(idx){
           ans+=bit[idx];
            idx-=(idx&(-idx));
        }
        return ans;
    }
    int sumRange(int i, int j) {
        return query(j)-query(i-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
