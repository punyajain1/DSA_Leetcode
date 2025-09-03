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
    ListNode* sortList(ListNode* head) {
        vector <int> v;
        ListNode* newl=head;
        while(newl!=nullptr){
            v.push_back(newl->val);
            newl=newl->next;
        }
        sort(v.begin(),v.end());
        ListNode* newh=new ListNode(0);
        newl=newh;
        for(int i =0;i<v.size();i++){
            newl->next = new ListNode(v[i]);
            newl=newl->next;
        }
        return newh->next;
    }
};