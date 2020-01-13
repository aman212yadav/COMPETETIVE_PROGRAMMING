/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// problem link - https://leetcode.com/contest/biweekly-contest-17/problems/sum-of-nodes-with-even-valued-grandparent/
class Solution {
public:
    int height(TreeNode* root){
        if(!root)
            return 0;
        return 1+max(height(root->left),height(root->right));

    }
    int sumEvenGrandparent(TreeNode* root) {

        int h=height(root);
        if(h==0)
            return 0;
        queue< TreeNode*> q;
        q.push({root});

        int ans=0;
        while(!q.empty()){
            TreeNode* p=q.front();
            q.pop();
            if(p->val%2==0){
                TreeNode *l=p->left,*r=p->right;
                if(l){
                    if(l->left)
                        ans+=l->left->val;
                    if(l->right)
                        ans+=l->right->val;
                }
                if(r){
                    if(r->left)
                        ans+=r->left->val;
                    if(r->right)
                        ans+=r->right->val;

                }

            }

            if(p->left)
                q.push(p->left);
            if(p->right)
                 q.push(p->right);

        }
        return ans;

    }
};
