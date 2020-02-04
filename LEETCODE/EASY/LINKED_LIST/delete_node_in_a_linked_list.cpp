/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// problem link - https://leetcode.com/problems/delete-node-in-a-linked-list
// time complexity - O(1)
// space complexity - O(1)
class Solution {
public:
    void deleteNode(ListNode* node) {
       *node=*node->next;
    }
};
