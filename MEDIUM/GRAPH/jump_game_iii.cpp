// problem link - https://leetcode.com/problems/jump-game-iii
// time complexity - O(n)
// space complexity - O(n)
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size()-1;
        if(arr[start]==0){
            return true;
        }
        queue<int> q;
        q.push(start);
        vector<bool> vis(n+1,0);
        vis[start]=true;
        while(!q.empty()){
            int idx=q.front();
            q.pop();
            if(idx+arr[idx]<=n && !vis[idx+arr[idx]]){
                if(arr[idx+arr[idx]]==0)
                    return true;
                q.push(idx+arr[idx]);
                vis[idx+arr[idx]]=true;
            }
            if(idx-arr[idx]>=0 && !vis[idx-arr[idx]]){
                if(arr[idx-arr[idx]]==0)
                    return true;
                q.push(idx-arr[idx]);
                vis[idx-arr[idx]]=true;
            }

        }
        return false;
    }
};
