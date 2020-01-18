// problem link - https://leetcode.com/problems/regions-cut-by-slashes
// space complexity - O(n*n)
// time complexity - O(n^3) can be easily improved to O(n^2log(n))

class Solution {
public:
    long long count,N;
    int find(int x,int f[]){
        if(x!=f[x])
        {
            f[x]=find(f[x],f);
        }
        return f[x];
    }

    void unionii(int x,int y,int f[]){
        int a=find(x,f);
        int b=find(y,f);
        if(a!=b)
        {
            count--;
        }
        f[a]=b;
    }

    int g(int i,int j,int c)
    {
        return 4*(i*N+j)+c;
    }
    int regionsBySlashes(vector<string>& grid) {
      int n=grid[0].size();
        N=n;
      int f[4*n*n];
        count=4*n*n;
      for(int i=0;i<4*n*n;i++)
             f[i]=i;
      for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){

              if(i>0)
                  unionii(g(i-1,j,2),g(i,j,0),f);
              if(j>0)
                  unionii(g(i,j-1,1),g(i,j,3),f);
              if(grid[i][j]!='\\')
              {
                   unionii(g(i,j,0),g(i,j,3),f);
                  unionii(g(i,j,2),g(i,j,1),f);
              }
              if(grid[i][j]!='/')
              {
                 unionii(g(i,j,0),g(i,j,1),f);
                  unionii(g(i,j,3),g(i,j,2),f);
              }

          }
      }
        return count;
    }
};
