/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// problem link - https://leetcode.com/problems/find-largest-value-in-each-tree-row
// time complexity - O(N)
// space complexity - O(N)
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(!root)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int ma=INT_MIN;
        while(!q.empty()){
            TreeNode *t=q.front();
            q.pop();
            if(t==NULL){
                ans.push_back(ma);
                ma=INT_MIN;
                if(q.empty())
                    break;
                q.push(NULL);
                continue;
            }
            ma=max(ma,t->val);
            if(t->left)
                q.push(t->left);
            if(t->right)
                q.push(t->right);

        }
        return ans;

    }
};
