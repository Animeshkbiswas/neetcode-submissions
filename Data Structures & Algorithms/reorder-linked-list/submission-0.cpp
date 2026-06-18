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

    void reorderList(ListNode* head) {
        int length=1;
        ListNode *y= head;
        if(head==nullptr){
            return;
        }
        while(y->next!=nullptr){
            length++;
            y=y->next;
        }
        y=head;
            for(int i=0; i<(length-1)/2; i++){
                y=y->next;
            }
            ListNode* second = y->next;
            y->next= nullptr;
            ListNode *curr=second;
            ListNode *prev=nullptr;
            while(curr!=nullptr){
                ListNode *temp=curr->next;
                curr->next= prev;
                prev=curr;
                curr=temp;
            }
            y=head;
            second=prev;
            while(second!=nullptr && y!=nullptr){
                ListNode *temp=y->next;
                y->next= second;
                ListNode *temp2=second->next;
                second->next=temp;
                y=temp;
                second= temp2;

            }
            

        
        
    }
};
