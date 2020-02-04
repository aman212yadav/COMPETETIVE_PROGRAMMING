/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// problem link - https://leetcode.com/problems/linked-list-cycle
// time complexity - O(n)

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *f=head,*s=head;
        while(f &&f->next){
            f=f->next->next;
            s=s->next;
            if(s==f)
                return true;
        }
        return false;

    }
};
