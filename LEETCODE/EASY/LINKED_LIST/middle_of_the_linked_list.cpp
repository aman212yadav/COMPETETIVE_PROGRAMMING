/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// problem link - https://leetcode.com/problems/middle-of-the-linked-list
// time complexity - O(N)
// space complexity - O(1)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        ListNode *f=head,*s=head;
        while(f && f->next){
            s=s->next;
            f=f->next->next;
        }
        return s;
    }
};
