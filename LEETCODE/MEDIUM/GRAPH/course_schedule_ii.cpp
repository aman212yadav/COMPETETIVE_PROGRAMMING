//problem link - https://leetcode.com/problems/course-schedule-ii
// space complexity - O(E+V)
// time complexity - O(V)
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector< vector<int> > gr(numCourses,vector<int>());
        vector<int> in(numCourses,0);
        for(auto k :  prerequisites){
            gr[k[1]].push_back(k[0]);
            in[k[0]]++;
        }
        vector<int> v;
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(in[i]==0){
                q.push(i);
                in[i]=-1;
            }
        }
        while(!q.empty()){
            int p=q.front();
            v.push_back(p);
            q.pop();
            for(auto k : gr[p]){
                in[k]--;
                if(in[k]==0){
                    q.push(k);
                    in[k]=-1;
                }
                
            }
            
        }
        
        if(v.size()==numCourses){
            return v;
        }else{
            
            return {};   
        }
        
        
        
    }
};
