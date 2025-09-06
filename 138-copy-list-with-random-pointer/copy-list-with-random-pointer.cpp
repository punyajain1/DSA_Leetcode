/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        Node* temp = head;
        while(temp!=nullptr){
            Node* t = new Node(temp->val);
            t->next = temp->next;
            temp->next=t;
            temp=temp->next->next;
        }
        temp=head;
        while(temp){
            Node* t = temp->next;
            if(temp->random!= nullptr){
                t->random = temp->random->next;
            }
            temp = temp->next->next;
        }
        temp=head;
        Node* newHead = temp->next;
        while(temp!=nullptr){
            Node* t = temp->next;
            temp->next = t->next;
            if(temp->next){
                t->next = temp->next->next;
            }
            temp=temp->next;
        }
        return newHead;
    }
};