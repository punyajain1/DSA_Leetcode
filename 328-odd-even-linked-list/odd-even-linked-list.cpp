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
        if (!head || !head->next) return head;
        ListNode* o = head;
        ListNode* eh = head->next;
        ListNode* e = eh;
        while(e!=nullptr && e->next!=nullptr){
            o->next=e->next;
            o=o->next;
            e->next=o->next;
            e=e->next;
        }
        o->next = eh;
        return head;
    }
};