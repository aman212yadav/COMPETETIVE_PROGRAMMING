// problem link - https://leetcode.com/problems/range-sum-of-bst

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
    // time complexity - O(N)
    void traverse(TreeNode* root, int L, int R,int &sum){
        if(root==NULL)
            return;
        if(root->val>=L && root->val <=R){
            sum+=root->val;
            traverse(root->left,L,R,sum);
            traverse(root->right,L,R,sum);
        } else if(root->val < L){
            traverse(root->right,L,R,sum);
        }else{
            traverse(root->left,L,R,sum);
        }
    }
    int rangeSumBST(TreeNode* root, int L, int R) {
        int sum=0;
        traverse(root,L,R,sum);
        return sum;
    }
};
