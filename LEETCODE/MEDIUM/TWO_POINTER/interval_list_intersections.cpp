// problem link - https://leetcode.com/problems/interval-list-intersections
// time complexity - O(n+m)
// space compplexity - O(n+m)
class Solution {
public:
    bool isIntersect(vector<int> &a,vector<int> &b){
         return a[0] <= b[0] && b[0]<=a[1] || b[0]<= a[0] && a[0]<=b[1];
    }
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B)      {

        vector< vector<int> > ans;
        int i=0,j=0,n=A.size(),m=B.size();
        while(i<n && j<m){

            if(isIntersect(A[i],B[j])){
                ans.push_back({max(A[i][0],B[j][0]),min(A[i][1],B[j][1])});
            }
                 if(B[j][1]>=A[i][1])
                 {
                     i++;
                 }else{
                     j++;
                 }
        }
        return ans;
     }
};
