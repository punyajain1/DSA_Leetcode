class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* d=new ListNode();
        ListNode* t=d;
        int carry=0;
        while(l1!=nullptr || l2!=nullptr || carry!=0){
            int sum =carry;
            if(l1){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2){
                sum+=l2->val;
                l2=l2->next;
            }
            carry=sum/10;
            ListNode* n = new ListNode(sum%10);
            t->next=n;
            t=t->next;
        }
        return d->next;
    }
};