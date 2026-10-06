class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* t1 = head;
        ListNode* t2 = head;
        int ct = 1;

        while(ct < k && t2 != nullptr){
            t2 = t2->next;
            ct++;
        }
        if(t2 == nullptr) {
            return head;
        }
        head = t2;
        ListNode* last = nullptr;

        while(t2 != nullptr){
            ListNode* t = t2->next;
            ListNode* curr = t1;
            ListNode* prev = t;

            while(curr != t){
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            if(last != nullptr){
                 last->next = t2;
            }
            last = t1;
            t1 = t;
            t2 = t;
            ct = 1;
            while(ct < k && t2 != nullptr){
                t2 = t2->next;
                ct++;
            }
        }
        return head;
    }
};