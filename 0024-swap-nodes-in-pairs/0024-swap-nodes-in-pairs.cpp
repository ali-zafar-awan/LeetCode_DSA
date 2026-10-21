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
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (!head)
            return head;
        ListNode *temp = head;
        ListNode *prev = nullptr; 
        bool flag = true;
        while (temp && temp->next)
        {
            ListNode *t = temp->next;
            temp->next = t->next;
            t->next = temp;
            if (flag)
            {
                head = t;
                flag = false;
            }else{
                prev->next = t;
            }
            prev = temp;
            temp = temp->next;
        }
        return head;
    }
};