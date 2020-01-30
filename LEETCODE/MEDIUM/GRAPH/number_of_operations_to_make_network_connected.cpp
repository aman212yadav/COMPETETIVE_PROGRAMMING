// problem link - https://leetcode.com/problems/number-of-operations-to-make-network-connected
// time complexity - O(number of edges * log(n))   by using optimised union find
// space complexity - O(n)
class Solution {
public:
    int find(vector<int> &par,int idx){
        if(idx!=par[idx])
            par[idx]=find(par,par[idx]);

        return par[idx];
    }
    void unioni(int x,int y,vector<int> &par){
        int u=find(par,x);
        int v=find(par,y);
        par[u]=par[v];
    }
    int makeConnected(int n, vector<vector<int>>& connections) {

        int extra=0,connected=n;
        vector<int> par(n),vis(n,0);
        for(int i=0;i<n;i++)
              par[i]=i;
        for(auto k : connections){
            int x=find(par,k[0]);
            int y=find(par,k[1]);
            if(x==y)
                extra++;
            else{
                connected--;
                unioni(x,y,par);
            }
        }

        if(connected <= 1)
            return 0;
        if(connected-1 >extra)
            return -1;
        else
            return connected-1;
    }
};
