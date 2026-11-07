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
    void rev(int t,int i,vector<int> &ans){
        while(t<=i){
            swap(ans[t],ans[i]);
            t++;
            i--;
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int> ans;
        ListNode* temp=head;
        while(temp){
            ans.push_back(temp->val);
            temp=temp->next;
        }
        int n=ans.size();
        int t=INT_MIN;
        for(int i=0;i<n;i++){

            if(t==INT_MIN) t=i;
            else if(i-t+1==k){
                rev(t,i,ans);
                t=INT_MIN;
            }
        }

        ListNode* dummynode=new ListNode(-1);
        ListNode* curr=dummynode;
        for(int i=0;i<n;i++){
            ListNode* newnode=new ListNode(ans[i]);
            curr->next=newnode;
            curr=curr->next;
        }
        return dummynode->next;
    }
};
