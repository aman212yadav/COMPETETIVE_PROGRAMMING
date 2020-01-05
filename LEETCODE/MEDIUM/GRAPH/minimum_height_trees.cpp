// problem link     - https://leetcode.com/problems/minimum-height-trees
// time complexity  - O(V)
// space complexity - O(E+V)
class Solution {
public:
    void dfs1(int u,int par,vector<int> &in,vector< vector<int> > &graph){
        in[u]=0;
        for(auto k : graph[u]){
            if(k==par){
                continue;
            }
            dfs1(k,u,in,graph);
            in[u]=max(in[u],1+in[k]);
        }
    }
    void dfs2(int u,int par,vector<int> &in,vector<int> &out,vector<vector<int> > &graph){
        int mx1(-1),mx2(-1);
        for(auto k:graph[u]){
            if(k==par)
                continue;
            if(mx1<=in[k])
            {
                mx2=mx1;
                mx1=in[k];
            }else if(mx2 < in[k]){
                mx2=in[k];
            }
        }
        for(auto k : graph[u]){
                if(k==par)
                    continue;
                int mx=mx1;
                if(mx1==in[k])
                    mx=mx2;
               out[k]=1+max(out[u],1+mx);
            dfs2(k,u,in,out,graph);
        }
        
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector< vector<int> > graph(n,vector<int>());
        for(auto k : edges){
            graph[k[0]].push_back(k[1]);
            graph[k[1]].push_back(k[0]);
        }
        vector<int> in(n,0),out(n,0);
        dfs1(0,-1,in,graph);
        dfs2(0,-1,in,out,graph);
        int mi=INT_MAX;
        for(int i=0;i<n;i++){
            mi=min(mi,max(in[i],out[i]));
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(max(in[i],out[i])==mi){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
