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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l=0;
        ListNode* temp=head;
        if(head==nullptr || head->next==nullptr) return nullptr;
        while(temp){
            l++;
            temp=temp->next;
        }

        if(l==n){
            ListNode* h=head;
            head=head->next;
            delete h;
            return head;
        }
        int step=l-n-1;
        ListNode* t=head;
        ListNode* slow=t;
        ListNode* fast=t->next;
        while(step--){
            slow=slow->next;
            fast=fast->next;
        }
        slow->next=fast->next;
        fast->next=nullptr;
        delete fast;
        return t;
    }
};
