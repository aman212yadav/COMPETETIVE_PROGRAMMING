/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// problem link - https://leetcode.com/problems/palindrome-linked-list
// time complexity - O(N)
// space complexity - O(1)
class Solution {
public:
    bool isPalin(ListNode* l1,ListNode* l2){
          while(l1 && l2 && l1->val==l2->val ){
              l1=l1->next;
              l2=l2->next;
          }
        return l1==NULL || l2==NULL;

    }
    ListNode* rever(ListNode *t){
        ListNode *prev=NULL,*Next;
        while(t){
            Next=t->next;
            t->next=prev;
            prev=t;
            t=Next;
        }
        return prev;

    }
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)
            return true;
     ListNode *s=head,*f=head;
        while(f && f->next){
            f=f->next->next;
            if(!f)
                break;
            s=s->next;
        }
        s=s->next;
        ListNode *l1=rever(s);

        return isPalin(head,l1);


    }
};
