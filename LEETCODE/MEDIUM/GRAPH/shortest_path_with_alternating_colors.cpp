// problem link - https://leetcode.com/problems/shortest-path-with-alternating-colors
// time complexity - O(E+V)
// space complexity - O(V)
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector< vector< pair<int,int> > > g(n);
        // red edges - 0 , blue edges - 1
        for(auto k : red_edges){
            g[k[0]].push_back({k[1],0});
        }
        for(auto k : blue_edges){
            g[k[0]].push_back({k[1],1});
        }
        vector< vector<int> > cost(n,vector<int>(2,-1));
        queue< pair<int,int> > q;
        q.push({0,0});
        q.push({0,1});
        cost[0]={0,0};
        while(!q.empty()){
            auto [i,c1]=q.front();
            q.pop();
            for(auto [j,c2] : g[i]){

                if(cost[j][c2]!=-1 || c1==c2)
                    continue;
                cost[j][c2]=1+cost[i][c1];
                q.push({j,c2});
            }
        }
        vector< int > res;
        for(auto k : cost){
            if(k[0]==-1)
                res.push_back(k[1]);
            else if(k[1]==-1)
                res.push_back(k[0]);
            else
                res.push_back(min(k[0],k[1]));
        }
        return res;
    }
};
