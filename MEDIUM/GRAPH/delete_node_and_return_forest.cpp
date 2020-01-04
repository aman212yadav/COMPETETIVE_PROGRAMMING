/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// problem link - https://leetcode.com/problems/delete-nodes-and-return-forest
// time complexity - O(n^2) but can be easily reduced to O(N) by using hashing
// space complexity - O(N)
class Solution {
public:
   TreeNode* helper(TreeNode* root,vector<int> &de,vector<TreeNode*> &ans,bool push_ready){
         if(root==NULL){
             return root;
         }
          if(find(de.begin(),de.end(),root->val)!=de.end()){
              root->left=helper(root->left,de,ans,true);
              root->right=helper(root->right,de,ans,true);
              root=NULL;
          }
          else{
              if(push_ready){
                  ans.push_back(root);
              }
              root->left=helper(root->left,de,ans,false);
              root->right=helper(root->right,de,ans,false);
          }
       return root; 
   }    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        helper(root,to_delete,ans,true);
        return ans;
        
    }
};
