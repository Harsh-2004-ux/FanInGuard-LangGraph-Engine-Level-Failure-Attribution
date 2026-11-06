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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        ListNode* dummynode=new ListNode(-1);
        ListNode* curr=dummynode;
        int carry=0;
        while(temp1!=nullptr && temp2!=nullptr){
            int a=temp1->val;
            int b=temp2->val;
            int sum=a+b+carry;
            curr->next=new ListNode(sum%10);
            carry=sum/10;
            curr=curr->next;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        if(carry==1){
            curr->next=new ListNode(1);
            curr=curr->next;
        }

        return dummynode->next;
    }
};