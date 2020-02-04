/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// problem link - https://leetcode.com/problems/intersection-of-two-linked-lists
// time complexity - O(N)
// space complexity - O(1)
class Solution {
public:
    int len(ListNode *l){
        if(!l)
            return 0;
        int le=0;
        while(l){
            le++;
            l=l->next;
        }
        return le;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
         int l1=len(headA),l2=len(headB);
         while(l1!=0 || l2!=0){
             if(l1>l2){
                 l1--;
                 headA=headA->next;
             }
             else if(l2>l1){
                 l2--;
                 headB=headB->next;
             }else{

                 l1--;
                 l2--;
                 if(headA==headB)
                     return headA;
                 headA=headA->next;
                 headB=headB->next;

             }
         }
        return NULL;

    }
};
