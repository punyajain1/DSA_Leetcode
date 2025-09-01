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
    ListNode* middleNode(ListNode* head) {
        if(head->next==nullptr){
            return head;
        }
        if(head->next->next==nullptr){
            return head->next;
        }
        ListNode* s=head;
        ListNode* f=head;

        while(f!=nullptr and f->next!=nullptr){
            f=f->next->next;
            s=s->next;
        }
        return s;
    }
};