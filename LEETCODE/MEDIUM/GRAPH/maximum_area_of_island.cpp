// problem link - https://leetcode.com/problems/max-area-of-island
// time complexity - O(N*M)
// space complexity - O(N*M)
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector< vector<bool> > vis(n,vector<bool>(m,false));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0 || vis[i][j])
                     continue;
                cout<<i<<" "<<j<<" ";
                queue<pair<int,pair<int,int> > > q;
                q.push({i,{j,1}});
                vis[i][j]=true;
                int co=1;
                while(!q.empty()){
                    pair< int ,pair<int , int> > p=q.front();
                    int x=p.first,y=p.second.first,dist=p.second.second;
                    q.pop();
                    if(x+1<n && !vis[x+1][y] && grid[x+1][y]){
                        q.push({x+1,{y,dist+1}});
                        vis[x+1][y]=true;
                       co++;
                    }
                    if(x-1>=0 && !vis[x-1][y] && grid[x-1][y]){
                        q.push({x-1,{y,dist+1}});
                        vis[x-1][y]=true;
                        co++;
                    }
                    if(y+1<m && !vis[x][y+1] && grid[x][y+1]){
                        q.push({x,{y+1,dist+1}});
                        vis[x][y+1]=true;
                        co++;
                    }
                    if(y-1>=0 && !vis[x][y-1] && grid[x][y-1]){
                        q.push({x,{y-1,dist+1}});
                        vis[x][y-1]=true;
                        co++;
                    }
                }
                ans=max(ans,co);
            }

        }
        return ans;

    }
};
