/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// problem link     - https://leetcode.com/problems/binary-tree-right-side-view
// time complexity - O(n)
// space complexity - O(height of tree)

class Solution {
public:
    void dfs(TreeNode* root,vector<int> &ans,int &mh,int cur){
        if(!root){
            return;
        }
        if(mh<cur){
            mh=cur;
            ans.push_back(root->val);
        }
        dfs(root->right,ans,mh,cur+1);
        dfs(root->left,ans,mh,cur+1);

    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        int mh=-1;
        dfs(root,ans,mh,0);
        return ans;
    }
};
