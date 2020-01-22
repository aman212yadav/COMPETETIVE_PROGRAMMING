// problem link - https://leetcode.com/problems/reverse-pairs
// time complexity - O(nlog(n))
// space complexity - O(n)
class Solution {
public:
    void merge(vector<int> &nums,int l,int r){
        long long i=l,j,m=(l+r)/2,co=0;
        j=m+1;
        vector<int> a(r-l+1);
        while(i<=m && j<=r){
            if(nums[i]>nums[j])
            { a[co++]=nums[j++];
            }
            else{
               a[co++]=nums[i++]; 
            }      
        }
        while(i<=m)
            a[co++]=nums[i++];
        while(j<=r)
            a[co++]=nums[j++];
            
        for(int i=0;i<co;i++)
            nums[i+l]=a[i];
     
        return ;
        
    }
    int solution(vector<int> &nums,int l,int r){
        if(l>=r)
            return 0;
       long long ans=0,m,i,j;
        m=(l+r)/2;
        ans+=solution(nums,l,m);
        ans+=solution(nums,m+1,r);
        i=l;
        j=m+1;
        while(i<=m && j<=r){
            if(nums[i]>(2LL)*nums[j])
            {ans+=m-i+1;
             j++;}
            else
                i++;
        }
      merge(nums,l,r);
        
        return ans;
    }
    int reversePairs(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        return solution(nums,0,nums.size()-1);
    }
};
