// probelem link - https://leetcode.com/problems/number-of-enclaves
// time complexity - O(n*m)

class Solution {
public:
    int  fill(vector<vector<int>>& A,int i,int j ){
        int n=A.size(),m=A[0].size();
        if(i<0 || i>n-1 || j<0 || j>m-1 || A[i][j]==0)
            return 0;
        A[i][j]=0;
        return 1+fill(A,i-1,j)+fill(A,i+1,j)+fill(A,i,j-1)+fill(A,i,j+1);

    }
    int numEnclaves(vector<vector<int>>& A) {
        int n=A.size(),m=A[0].size(),ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || i==n-1 || j==0 || j==m-1) &&A[i][j])
                    fill(A,i,j);
            }

        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(A[i][j])
                {ans+=fill(A,i,j);
                }
            }
        }
        return ans;
    }
};
