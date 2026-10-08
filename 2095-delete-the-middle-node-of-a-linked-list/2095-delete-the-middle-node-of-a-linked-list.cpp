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
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next) {
            return nullptr;
        }
        ListNode* slow= head;
        ListNode* fast= head->next;
        ListNode* prev = nullptr;
        int ct =1;
        bool flag = true;
        while(fast != nullptr){
            if(flag){
                prev = slow;
                slow=slow->next;
                fast = fast->next;
                flag = false;
            }else{
                fast = fast->next;
                flag = true;
            }
        }
        prev->next=slow->next;
        delete slow;
        return head;
    }
};