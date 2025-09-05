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
    ListNode* find(ListNode* head , int k){
        while(head!=nullptr && k-->0){
            head=head->next;
        }
        return head;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        int c=1;
        ListNode* tail=head;
        while(tail->next!=nullptr){
            c++;
            tail=tail->next;
        }
        k = k%c; // important thing it finds the number at which new last will be present (likr it gives thr number of last elements needed to come in front)
        if(k==0) return head;
        tail->next = head;
        ListNode* newlast=find(head,c-k-1);//(c-k-1) = gives the number elements from front that should be needed to move to last
        //we are changing head to newlast->next and newlast->next will point to null
        head=newlast->next;
        newlast->next = nullptr;
        return head;
    }
};