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
    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode dummy;
        ListNode* t = &dummy;
        while (a && b) {
            if (a->val <= b->val) {
                t->next = a;
                a = a->next;
            } else {
                t->next = b; b = b->next;
            }
            t = t->next;
        }
        if(a){
            t->next = a;
        }else{
            t->next = b;
        }
        return dummy.next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int s = lists.size();
        if (s==0){
            return nullptr;
        }
        ListNode* t = lists[0];
        for (int i = 1; i < s; i++) {
            t = merge(t, lists[i]);
        }
        return t;
    }
};