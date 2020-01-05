/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// problem link - https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves
// time complexity - O(N)
// space complexity - O(N)
class Solution {
public:
    int dfs(TreeNode* root){
        if(root==NULL){
            return -1;
            }
        return 1+max(dfs(root->left),dfs(root->right));
        
    }
    TreeNode* lca(TreeNode* root,int depth,int d){
           if(root==NULL){
               return NULL;
           }
           if(depth==d){
               return root;
           }
           TreeNode* l=lca(root->left,depth+1,d),*r=lca(root->right,depth+1,d);
        if(l &&  r)
            return root;
        else
            return l==NULL?r:l;
        
        
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int d=dfs(root);
        return lca(root,0,d);
    }
};
