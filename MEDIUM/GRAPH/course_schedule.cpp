// problem link - https://leetcode.com/problems/course-schedule
// time complexity - O(E+v)
//space complexity - O(E+V)
class Solution {
public:
    bool isCycle(int u,vector<bool> &vis,vector<vector<int> > &graph,vector<int> &instack){
        vis[u]=1;
        instack[u]=true;
        for(auto v:graph[u]){
            if(instack[v])
                return true;

            if(!vis[v]&&isCycle(v,vis,graph,instack) )
                return true;
        }
        instack[u]=false;
        return false;

    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
     vector<vector<int> > graph(numCourses);
        for(auto k : prerequisites){
            graph[k[1]].push_back(k[0]);
        }
        vector<bool> vis(numCourses,0);
        for(int i=0;i<numCourses;i++){
            vector<int> m(numCourses,0);
            if(vis[i]==0 && isCycle(i,vis,graph,m)){
                return false;
            }

        }
        return true;

    }
};
