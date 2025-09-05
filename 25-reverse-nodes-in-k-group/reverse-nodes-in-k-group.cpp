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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* node = head;
        int count = 0;
        while(node != NULL && count < k){
            node = node->next;
            count++;
        }
        if(count<k){
            return head;
        }
        ListNode* next=nullptr;
        ListNode* curr=head;
        ListNode* prev=nullptr;
        int cnt=0;
        while(cnt<k && curr!=nullptr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            cnt++;
        }
        if(next != NULL){
            head->next = reverseKGroup(next, k);
        }
        return prev;
    }
};