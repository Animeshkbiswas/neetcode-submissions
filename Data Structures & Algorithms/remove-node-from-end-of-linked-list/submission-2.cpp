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
        int x=1;
        ListNode *y=head;
        while(y->next!=nullptr){
            x++;
            y=y->next;
        }
        n= x-n-1;
        int i=0;
        y=head;
        if(x==1){
            return nullptr;
        }
        if(n == -1){
            return head->next;
            }
        while(i<=x){
            if(i==n){
                 ListNode *temp=y;
                y=y->next;
                temp->next=y->next;
                break;
            }
            else{
                y=y->next;
                i++;
            }
        }
    return head;
    }
};
