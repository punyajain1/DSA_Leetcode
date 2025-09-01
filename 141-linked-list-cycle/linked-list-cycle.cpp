/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return false;
    }
    ListNode *s = head;
    ListNode *f = head->next;
    while (f != nullptr && f->next != nullptr) {
        if (s==f) {
            return true;
            break;
        }
        s = s->next;
        f = f->next->next;
    }
    return false;
}

};