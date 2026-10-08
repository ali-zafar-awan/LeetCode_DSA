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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode dummy(0, head);
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;
        ListNode* prev = nullptr;

        for (int i = 0; i < k; i++) {
            prev = fast;
            fast = fast->next;
        }
        ListNode* p1 = prev;
        ListNode* n1 = fast;

        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* p2 = slow;
        ListNode* n2 = slow->next;

        if (n1 == n2){
            return dummy.next;
        }

        p1->next = n2;
        p2->next = n1;

        ListNode* temp = n1->next;
        n1->next = n2->next;
        n2->next = temp;

        return dummy.next;
    }
};