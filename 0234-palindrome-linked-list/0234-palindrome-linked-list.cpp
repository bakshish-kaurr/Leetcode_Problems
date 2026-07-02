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

    bool check(ListNode* head) {
        if (head == NULL)
            return true;

        if (!check(head->next))
            return false;

        if (head->val != start->val)
            return false;

        start = start->next;

        return true;
    }

    bool isPalindrome(ListNode* head) {
        start = head;
        return check(head);
    }
};