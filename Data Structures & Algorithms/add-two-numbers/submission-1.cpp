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
        ListNode* c1=l1;
        ListNode* c2=l2;
        int carry=0;
        ListNode* last_c1;
        while(c1!=nullptr ||c2!=nullptr ||carry!=0){
           if(c1!=nullptr){
            int k=0;
            if(c2!=nullptr){
                k=c2->val;
                c2=c2->next;
            }
            c1->val+= k+carry;
            if(c1->val>9){
                c1->val-=10;
                carry=1;
                
            }
            else{
                carry=0;
            }
            last_c1=c1;
            c1=c1->next;
           }
            else{
                int k=0;
                if(c2!=nullptr){
                    k=c2->val;
                    c2=c2->next;
                }
                ListNode *v= new ListNode(k+carry);
                carry=0;
                last_c1->next= v;
                c1=v;
            }
        }
        return l1;
    }
};
