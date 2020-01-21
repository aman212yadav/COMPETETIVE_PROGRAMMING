// problem link - https://leetcode.com/problems/count-of-smaller-numbers-after-self
// query  - O(log(n))
// update - O(log(max_element_value))
class Solution {
    int n;
public:
    void update(int i,int val,vector<int> &bit){
        while(i<=n){
            bit[i]+=val;
            i+=(i&(-i));
        }

    }
    int query(int i,vector<int> &bit){
        int ans=0;
        while(i){
            ans+=bit[i];
            i-=(i&(-i));
        }
        return ans;
    }
    vector<int> countSmaller(vector<int>& nums) {
        if(!nums.size())
            return vector<int>();
      int ma=*max_element(nums.begin(),nums.end()),mi=*min_element(nums.begin(),nums.end()),r=nums.size();
        if(mi<0)
            mi=-mi;
        else
            mi=0;
        n=ma+mi+1;
      vector<int> bit(mi+ma+2,0);
       vector<int> count(r,0);

        update(mi+1+nums.back(),1,bit);
        for(int i=r-2;i>=0;i--){
            count[i]=query(mi+nums[i],bit);
            update(mi+1+nums[i],1,bit);
        }
        return count;
    }
};
