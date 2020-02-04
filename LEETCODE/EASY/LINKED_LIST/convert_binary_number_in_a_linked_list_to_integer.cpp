// problem link - https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer
// time complexity - O(n)
// space complexity - O(1)
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ans=0;
        while(head){
            ans=ans*2+head->val;
            head=head->next;
        }
        return ans;
    }
};
