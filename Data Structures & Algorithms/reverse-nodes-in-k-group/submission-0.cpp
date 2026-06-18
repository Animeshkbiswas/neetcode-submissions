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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count=1;
        ListNode* curr =head;
        if(head == nullptr || k == 1) return head;
        while(curr->next!= nullptr){
            count++;
            curr= curr->next;
        }
        int groups=count/k;
        ListNode* b =nullptr;
        ListNode* c=head;
        ListNode* ans=nullptr;
        while(groups!=0){    
            ListNode* tail = c;  
            ListNode* prev=b;
            ListNode* cur=c;
            for(int i=1; i<=k; i++){
                ListNode* temp= cur->next;
                cur->next= prev;
                prev= cur;
                cur= temp;
            }
            if(groups==count/k){
                ans=prev;
            }
            else{
                    b->next = prev;
                 }
            b=tail;
            c=cur;
            groups--;

        }
        b->next = c;
        return ans;
    }
};
