/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// problem link - https://leetcode.com/problems/reverse-linked-list
// time complexity - O(n)
// space complexity - O(1)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
     ListNode *prev=NULL,*Next;
        while(head){
            Next=head->next;
            head->next=prev;
            prev=head;
            head=Next;
        }
        return prev;

    }
};
