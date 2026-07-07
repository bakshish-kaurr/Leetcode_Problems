/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int solve(ListNode *head,int ans)
    {
        if(head==NULL)
        return ans;
        ans=ans*2+head->val;
        return solve(head->next,ans);
    }
    int getDecimalValue(ListNode* head) {
        return solve(head,0);
    }
};