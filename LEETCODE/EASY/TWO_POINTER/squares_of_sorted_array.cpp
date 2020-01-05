// problem link - https://leetcode.com/problems/squares-of-a-sorted-array
// time complexity - O(n)
// space complexity - O(n)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int l=0,r=A.size()-1,idx=A.size()-1;
        vector<int> b(A.size());
         while(idx>=0){
             if(abs(A[l])>abs(A[r])){
                 b[idx]=A[l]*A[l];
                 l++;
             }
             else{
                 b[idx]=A[r]*A[r];
                 r--;
             }
             idx--;
         }
    return b;
    }
};
