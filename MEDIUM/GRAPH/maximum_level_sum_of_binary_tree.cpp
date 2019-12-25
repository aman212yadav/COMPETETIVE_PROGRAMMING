/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 // problem link - https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree
class Solution {
public:
    // time complexity - O(n)
    // space complexity - o(n)
    int maxLevelSum(TreeNode* root) {
        int ma=INT_MIN,lm=-1,l=1,sum=0;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode *node=q.front();
            q.pop();
            if(node==NULL){
                if(ma<sum){
                    ma=sum;
                    lm=l;

                }
                if(!q.empty()){
                    q.push(NULL);
                }
                  l++;
                sum=0;
                continue;
            }
            sum+=node->val;
            if(node->left){
                 q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        return lm;
    }
};
