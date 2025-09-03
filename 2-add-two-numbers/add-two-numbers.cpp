class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* d=new ListNode();
        ListNode* t=d;
        int carry=0;
        while(l1!=nullptr || l2!=nullptr || carry!=0){
            int sum =carry;
            if(l1!=nullptr) sum+=l1->val;
            if(l2!=nullptr) sum+=l2->val;

            carry=sum/10;
            ListNode* n = new ListNode(sum%10);
            t->next=n;
            t=t->next;
            if (l1 != nullptr) l1=l1->next;
            if (l2 != nullptr) l2=l2->next;
        }
        return d->next;
    }
};