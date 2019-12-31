// problem link - https://leetcode.com/problems/find-eventual-safe-states
// time complexity - O(E+V)
// space complexity - O(n)
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int> > rg(n);
        vector<int> in(n,0),safe(n,0);
        queue<int> q;
        for(int i=0;i<graph.size();i++){
            if(graph[i].size()==0){
                q.push(i)    ;
                safe[i]=true ;
            } else {
                for(auto j:graph[i])
                {rg[j].push_back(i);
                    in[i]++;
                }
            }
        }
        while(!q.empty()){
            int k=q.front();
            q.pop();
            for(auto j : rg[k]){
                 in[j]-- ;
                if(in[j]==0){
                    safe[j]=true;
                    q.push(j);
                }
            }
        }
        vector<int> s;
        for(int i=0;i<n;i++){
            if(safe[i])
                s.push_back(i);
        }
        return s;
    }
};
