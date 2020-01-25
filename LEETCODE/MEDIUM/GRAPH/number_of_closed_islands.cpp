// problem link - https://leetcode.com/problems/number-of-closed-islands
// time complexity - O(n*m)

class Solution {
public:
    void fill(vector< vector<int> > &grid,int i,int j){
        if(i<0 || i>grid.size()-1 || j<0 || j> grid[0].size()-1 || grid[i][j])
            return ;
        grid[i][j]=1;
        fill(grid,i,j-1);fill(grid,i,j+1);fill(grid,i-1,j);fill(grid,i+1,j);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(i==0 || i==n-1 || j==0 || j==m-1)
                    fill(grid,i,j);

        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                if(grid[i][j]==0){
                    res++;
                    fill(grid,i,j);
                }

        }
        return res;
    }
};
