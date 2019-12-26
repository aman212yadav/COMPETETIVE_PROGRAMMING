// problem link - https://leetcode.com/problems/redundant-connection
class Solution {
public:
    // time complexity - O(n^2) can be easily optimised to nlogn using path compression and rank
    // space complexity -O(n)
    int findPar(unordered_map<int,int> &m,int x){
        if(m[x]==0 || m[x]==x){
            return x;
        }
        int u=findPar(m,m[x]);
        m[x]=u;
       return u;
    }
    void union_(int x,int y,unordered_map<int,int> &m){
        m[x]=y;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int,int> m;
        for(auto k : edges){
            int u=findPar(m,k[0]);
            int v=findPar(m,k[1]);
            //cout<<u<<" "<<v<<"\n";
            if(u==v){
                return {k[0],k[1]};
            }
            union_(u,v,m);
        }
        return {};
    }
};
