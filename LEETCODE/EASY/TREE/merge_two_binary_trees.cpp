/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// problem link - https://leetcode.com/problems/merge-two-binary-trees
// time complexity - O(N+M)  (n,m are number of nodes in a tree)
// space complexity - O(1)
class Solution {
public:
    TreeNode *merge(TreeNode *t1,TreeNode *t2){
        if(t1==NULL || t2==NULL){
            return (t2==NULL?t1:t2);
        }
        t1->val+=t2->val;
        t1->left=merge(t1->left,t2->left);
        t1->right=merge(t1->right,t2->right);
        return t1;
    }
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1==NULL || t2==NULL){
            return (t2==NULL?t1:t2);
        }
        return merge(t1,t2);
    }
};
