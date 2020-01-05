/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// problem link - https://leetcode.com/problems/maximum-difference-between-node-and-ancestor

// time complexity - O(N)
// space complexity - O(H)
class Solution {
public:
    int postOrder(TreeNode *root,int mx=-1,int mi=INT_MAX){
        if(root==NULL)
            return 0;
        mx=max(mx,root->val);
        mi=min(mi,root->val);
        int left=postOrder(root->left,mx,mi),right=postOrder(root->right,mx,mi);
        return max(abs(mx-mi),max(left,right));
        
    }
    int maxAncestorDiff(TreeNode* root) {
        return postOrder(root);
    }
};
