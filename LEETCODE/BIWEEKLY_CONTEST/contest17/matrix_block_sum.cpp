// problem link - https://leetcode.com/contest/biweekly-contest-17/problems/matrix-block-sum/
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {

        int n=mat.size(),m=mat[0].size();
        vector< vector<int> > v(n,vector<int>(m,0)),ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0){
                    v[i][j]=mat[i][j];
                    if(j-1>=0)
                        v[i][j]+=v[i][j-1];
                    continue;
                }
                if(j==0){
                    v[i][j]=mat[i][j]+v[i-1][j];
                }else{
                    v[i][j]=v[i-1][j]+v[i][j-1]-v[i-1][j-1]+mat[i][j];
                }

            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int idx=i-k-1,idy=j-k-1,idux=min(n-1,i+k),iduy=min(m-1,j+k),an;
                an=v[idux][iduy];
                if(idx>=0){
                    an-=v[idx][iduy];
                }
                if(idy>=0){
                    an-=v[idux][idy];
                }
                if(idx>=0 && idy>=0)
                    an+=v[idx][idy];
                ans[i][j]=an;
            }
        }
        return ans;
    }
};
