// problem link - https://leetcode.com/problems/count-servers-that-communicate
// time complexity - O(n*m)
// space complexity - O(n*m)
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        if(grid.size()==0)
            return 0;
        int n=grid.size(),m=grid[0].size(),ans=0;
        vector<int> row(n,0),col(m,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++){
                 if(grid[i][j]==1)
                 {
                     row[i]++;
                     col[j]++;
                 }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++){
                 if(grid[i][j]==1 && (row[i]>1 ||col[j]>1) )
                 {
                     ans++;
                 }
            }
        }

        return ans;
    }
};
