// problem link - https://leetcode.com/problems/as-far-from-land-as-possible
// time complexity - O(N*N)
// space compexity - O(N*N)
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue< pair<int,int> > q;
        int n=grid.size(),x,y;
        vector< vector<int> > cost(n, vector<int> (n,INT_MAX) );
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    cost[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        if(q.size()==0 || q.size()==n*n){
            return -1;
        }
        vector< pair<int,int> > dir={{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            pair<int,int> p=q.front();
            x=p.first;
            y=p.second;
            q.pop();
            for(int i=0;i<4;i++){
               if(x+dir[i].first>=0 && x+dir[i].first<n && y+dir[i].second>=0 && y+dir[i].second<n && cost[x+dir[i].first][y+dir[i].second]>cost[x][y]+1){
                  cost[x+dir[i].first][y+dir[i].second]=cost[x][y]+1;
                   q.push({x+dir[i].first,y+dir[i].second});
               }

            }
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans=max(ans,cost[i][j]);
            }
        }
        return ans;

    }
};
