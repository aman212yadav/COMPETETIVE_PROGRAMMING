// problem link - https://leetcode.com/problems/friend-circles
// time complexity - O(N*N)
// space complexity - O(N)
class Solution {
public:
    void helper(vector<vector<int>>& M,vector<bool> &vis,int idx){
                                vis[idx]=1;
           for(int i=0;i<M.size();i++){
               if(i==idx)
                    continue;
               if(!vis[i] && M[idx][i])
                   helper(M,vis,i);
           }
                                                                 
                                                                 
                                                                 }
    int findCircleNum(vector<vector<int>>& M) {
        int ans=0,n=M.size();
        vector<bool> vis(M.size(),0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i]){
                ans++;
                helper(M,vis,i);
            }
        }
        return ans;
    }
};
