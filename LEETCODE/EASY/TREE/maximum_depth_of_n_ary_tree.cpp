// problem link - https://leetcode.com/problems/maximum-depth-of-n-ary-tree
// time complexity - O(N)
// space complexiyt - O(N)

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    int maxDepth(Node* root) {
        if(root==NULL)
            return 0;
        int ma=0;
        for(auto k : root->children){
            ma=max(ma,maxDepth(k));
        }
        return 1+ma;

    }
};
