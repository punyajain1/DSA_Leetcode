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
    ListNode* findk(ListNode* h,int k){
        ListNode* temp = h;
        while(--k && temp!=nullptr){
            temp=temp->next;
        }
        return temp;
    }
    ListNode* reversel(ListNode* h){
        ListNode* prev = nullptr;
        while(h!=nullptr){
            ListNode* f=h->next;
            h->next=prev;
            prev=h;
            h=f;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prev=nullptr;
        while(temp!=nullptr){
            ListNode* kth = findk(temp,k);
            if(kth==nullptr){
                if(prev) prev->next=temp;
                break;
            }
            ListNode* newl=kth->next;
            kth->next=nullptr;    
            reversel(temp);
            if(temp==head){
                head=kth;
            }else{
                prev->next=kth;
            }
            prev = temp;
            temp = newl;
        }
        return head;
    }
};