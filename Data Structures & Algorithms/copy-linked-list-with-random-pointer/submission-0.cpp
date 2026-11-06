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
    void insertNode(Node* head){
        Node* temp=head;
        while(temp){
            Node* copynode=new Node(temp->val);
            copynode->next=temp->next;
            temp->next=copynode;
            temp=temp->next->next;
        }
    }

    void connectrandom(Node* head){
        Node* temp=head;
        while(temp){
            Node* copynode=temp->next;
            if(temp->random){
                copynode->random=temp->random->next;
            }
            else{
                copynode->random=nullptr;
            }
            temp=temp->next->next;
        }

    }
    Node* freeoriginal(Node* head){
        Node* temp=head;
        Node* dummynode=new Node(-1);
        Node* res=dummynode;
        while(temp){
            res->next=temp->next;
            res=res->next;
            temp->next=temp->next->next;
            temp=temp->next;
        }
        return dummynode->next;
    }
    Node* copyRandomList(Node* head) {
        insertNode(head);
        connectrandom(head);
        return freeoriginal(head);
    }
};
