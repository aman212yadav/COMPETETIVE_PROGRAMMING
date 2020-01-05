/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// problem link - https://leetcode.com/problems/find-bottom-left-tree-value
// time complexity - O(n)
// space complexity - O(n)
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode* > q;
        q.push(root);
        int ans;
        while(!q.empty()){
            TreeNode *t=q.front();
            q.pop();
            ans=t->val;
            if(t->right)
                q.push(t->right);
            if(t->left)
                q.push(t->left);

        }
        return ans;

    }
};
