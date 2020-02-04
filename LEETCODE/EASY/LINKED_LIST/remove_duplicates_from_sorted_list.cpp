/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// problem link - https://leetcode.com/problems/remove-duplicates-from-sorted-list
// time complexity - O(N)
// space complexity - O(N);  can be optimised to O(1) using iterative approach
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || !head->next)
            return head;
        if(head->val == head->next->val){
            *head=*head->next;
            return deleteDuplicates(head);
        }
        else{
            head->next=deleteDuplicates(head->next);
            return head;
        }
    }
};
