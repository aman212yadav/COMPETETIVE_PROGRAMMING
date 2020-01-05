class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
     vector< vector<int> > v(N+1);
        for(auto k:paths){
            v[k[0]-1].push_back(k[1]-1);
            v[k[1]-1].push_back(k[0]-1);
        }
        vector<int> answer(N,0);
        for(int i=0;i<N;i++ ){
            int used[5]={0};
            for(auto k : v[i]){
                used[answer[k]]=1;
            }
            for(int k=1;k<=4;k++){
                if(!used[k]){
                    answer[i]=k;
                }
            }
        }
        return answer;
    }
};
