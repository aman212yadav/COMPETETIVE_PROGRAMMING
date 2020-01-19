/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// problem link - https://leetcode.com/contest/weekly-contest-172/problems/delete-leaves-with-a-given-value/
// time complexity - O(N)
// space complexity - O(N) (system stack)
class Solution {
public:
    bool delLeaf(TreeNode* &root, int target){
        if(root==NULL){
            return true;
        }

        bool l=delLeaf(root->left,target),r=delLeaf(root->right,target);
        if(l && r && root->val==target){
            root=NULL;
            return true;
        }

        return false;


    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
      delLeaf(root,target);
        return root;

    }
};
