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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return head;
        }
        ListNode* odd = head;
        ListNode* prev = head->next;
        ListNode* temp = prev->next;
        int ct = 3 ;
        
        while(temp != nullptr){
            if(ct%2==1){
                ListNode* t = odd->next;
                prev->next = temp->next;
                odd->next = temp;
                odd=temp;
                odd->next=t;
                temp = prev->next;
            }else{
                prev = temp; 
                temp=temp->next;
            }
            ct++;
        }
        return head;
    }
};