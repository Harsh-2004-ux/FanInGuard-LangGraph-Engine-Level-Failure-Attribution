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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(lists.empty()) return {};
        int n=lists.size();
        vector<int> ans;
        for(auto it:lists){
            ListNode* head=it;
            while(head){
                ans.push_back(head->val);
                head=head->next;
            }
        }
        sort(ans.begin(),ans.end());
        if(ans.empty()) return {};
        ListNode* dummynode=new ListNode(-1);
        ListNode* curr=dummynode;
        for(auto it:ans){
            ListNode* newnode=new ListNode(it);
            curr->next=newnode;
            curr=curr->next;
        }
        return dummynode->next;
    }
};
