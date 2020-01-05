// problem link - https://leetcode.com/problems/convert-bst-to-greater-tree
// time complexity - O(n)
// space complexity - O(n)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void post(TreeNode* root,int &sum){
        if(root==NULL)
            return ;
        post(root->right,sum);
        root->val+=sum;
        sum=root->val;
        post(root->left,sum);
    }
    TreeNode* convertBST(TreeNode* root) {
        int sum=0;
        post(root,sum);
        return root;
    }
};
