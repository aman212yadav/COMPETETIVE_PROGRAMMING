// problem link - https://leetcode.com/problems/is-graph-bipartite
// time complexity - O(N+E)
// space complexity - O(N)
class Solution {
public:
    bool bipart(vector<vector<int>>& v,vector<int> &co,int src){
         co[src]=1;
        queue<int> q;
        q.push(src);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto k : v[u] ){
                if(co[u]==co[k]){
                    return false;
                }else if(co[k]==-1){
                    co[k]=1-co[u];
                    q.push(k);
                }
            }
        }
        return true;

    }
    bool isBipartite(vector<vector<int>>& graph) {
         int n=graph.size();
         vector< vector<int> > &v=graph;

        vector<int> co(n,-1);
        bool ans=true;
        for(int i=0;i<n;i++){
            if(co[i]==-1)
                ans=ans&bipart(graph,co,i);
        }

        return ans;

    }
};
