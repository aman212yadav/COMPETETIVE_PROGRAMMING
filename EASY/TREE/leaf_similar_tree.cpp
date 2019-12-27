// problem link - https://leetcode.com/problems/leaf-similar-trees
// time complexity - O(N)
//space complexity - O(N)

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
    void dfs(TreeNode* node,vector<int> &v){
        if(node==NULL)
            return ;
        if(!node->left && !node->right)
        {
            v.push_back(node->val);
            return;
        }
        dfs(node->left,v);
        dfs(node->right,v);

    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1,v2;
        dfs(root1,v1);
        dfs(root2,v2);
        return v1==v2;
    }
};
