// problem link - https://leetcode.com/problems/most-stones-removed-with-same-row-or-column
// time complexity - O(nlog(n))
// space complexity - O(n)
class Solution {
public:
    int find(vector<int> &par,int idx){
        if(idx==par[idx])
            return idx;
        par[idx]=find(par,par[idx]);
        return par[idx];
    }
    void unioon(vector<int> &par,int u,int v){
        int x=find(par,u);
        int y=find(par,v);
        if(x!=y)
            par[x]=y;

    }
    int removeStones(vector<vector<int>>& stones) {
      vector<int> par(2*10000);
        for(int i=0;i<2*10000;i++)
            par[i]=i;
        for(auto k : stones)
            unioon(par,k[0],k[1]+10000);
        set<int> s;
        for(auto k : stones)
            s.insert(find(par,k[0]));
        return stones.size()-s.size();

    }
};
