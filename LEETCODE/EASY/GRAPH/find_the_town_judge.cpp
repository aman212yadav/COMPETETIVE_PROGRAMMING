// problem link - https://leetcode.com/problems/find-the-town-judge

class Solution {
public:

    // time complexity - O(n)
    // space complexity -O(N)
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> inn(N,0);
        for(auto k : trust){
            inn[k[0]-1]--;
            inn[k[1]-1]++;
        }
        for(int i=0;i<N;i++){
            if(inn[i]==N-1)
                return i+1;
        }
        return -1;
    }
};
