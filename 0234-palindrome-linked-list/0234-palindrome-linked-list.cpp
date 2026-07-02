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
    ListNode* start;
    bool isPalin(ListNode* head)
    {
        if (head==NULL)
        return true;
        bool check=isPalin(head->next) & head->val==start->val;
        start=start->next;
        return check;
    }
    bool isPalindrome(ListNode* head) {
        start=head;
        return isPalin(head);
    }
};