// problem link - https://leetcode.com/problems/keys-and-rooms
class Solution {
public:
    // time complexity - O(V+E)
    // space complexity - O(V*E)
    void dfs(int s,vector<vector<int>>& rooms,vector<bool> &vis){
        vis[s]=true;
        for(auto k : rooms[s]){
            if(!vis[k]){
                dfs(k,rooms,vis);
            }
        }

    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> vis(rooms.size(),false);
        dfs(0,rooms,vis);
        for(auto k: vis){
            if(!k)
                return false;
        }
        return true;

    }
};
