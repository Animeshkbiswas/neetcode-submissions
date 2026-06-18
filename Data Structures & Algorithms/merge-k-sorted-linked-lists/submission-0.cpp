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
    ListNode* mergetwolists(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode(0);
        ListNode* node= dummy;
        while(l1 && l2){
            if(l1->val<l2->val){
                dummy->next=l1;
                l1= l1->next;
            }
            else{
                dummy->next=l2;
                l2= l2->next;
            }
            dummy= dummy->next;
        }
        if(l1==nullptr){
            dummy->next=l2;
        }
        else{
             dummy->next=l1;
        }
        return node->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int x= lists.size();
        ListNode* ans=lists[0];
        if(x==0){
            return nullptr;
        }
        for(int i=1;i<x; i++){
           ans=  mergetwolists(ans,lists[i]);
        }






        return ans;




    }
};
