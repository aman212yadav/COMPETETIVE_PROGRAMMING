/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// problem link - https://leetcode.com/problems/remove-linked-list-elements
// time complexity - O(n)
// space complexity - O(1)
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)
            return head;
        ListNode *temp=head;
        while(temp->next){
            if(temp->next->val==val){
                temp->next=temp->next->next;
            }
            else{
                temp=temp->next;
            }

        }
        if(head->val==val)
            return head->next;
        return head;
    }
};
