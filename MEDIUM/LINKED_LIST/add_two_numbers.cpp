/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


 // problem link - https://leetcode.com/problems/add-two-numbers

class Solution {
public:
    // time complexity - O(max(n1,n2)
    // space complexity - O(max(n1,n2))
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3=NULL,*temp;
        int carry=0;
        while(l1 && l2){
            carry=carry+l1->val+l2->val;
            if(l3==NULL){
                l3=new ListNode(carry%10);
                temp=l3;

            }else{
                temp->next=new ListNode(carry%10);
                temp=temp->next;
            }
            l1=l1->next;
            l2=l2->next;
            carry=carry/10;
        }
        while(l1){
            carry=carry+l1->val;
            if(l3==NULL){
                l3=new ListNode(carry%10);
                temp=l3;
            }else{
                 temp->next=new ListNode(carry%10);
                temp=temp->next;
            }
            carry=carry/10;
            l1=l1->next;
        }
        while(l2){
            carry=carry+l2->val;
            if(l3==NULL){
                l3=new ListNode(carry%10);
                temp=l3;
            }else{
                temp->next=new ListNode(carry%10);
                temp=temp->next;
            }
            l2=l2->next;
            carry=carry/10;
        }
        if(carry){
            if(l3==NULL){
                l3=new ListNode(carry);
            }else{
                 temp->next=new ListNode(carry);
                temp=temp->next;
            }
        }
        return l3;

    }
};
