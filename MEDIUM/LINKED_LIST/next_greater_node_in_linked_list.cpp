/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// problem link - https://leetcode.com/problems/next-greater-node-in-linked-list
class Solution {
public:

    // time complexity - O(n)
    // space complexity - O(n)
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> v;
        while(head){
            v.push_back(head->val);
            head=head->next;
        }
        vector<int> res(v.size());
        stack<int> stk;
        for(int i=v.size()-1;i>=0;i--){
            if(stk.empty()){
                 res[i]=0;
                stk.push(v[i]);
            }else{
                while(!stk.empty() && v[i]>= stk.top())
                    stk.pop();
                if(stk.empty()){
                    res[i]=0;
                }else{
                    res[i]=stk.top();
                }
                stk.push(v[i]);
            }
        }
        return res;
    }
};
