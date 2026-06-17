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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        int x;
        ListNode* head=nullptr;
        ListNode* tail=nullptr;
        if(list1==nullptr && list2==nullptr){
            return list1;
        }
        while(list1!=nullptr && list2!=nullptr){
       
        if(list1->val<=list2->val){
         x= list1->val;
         ListNode* y= new ListNode (x);
         if(head==nullptr){
                head= y;
                tail=y;
            }
            else{
                tail->next= y;
                tail=y;
            }
         list1= list1->next;
        }
        else{
            x= list2->val;
           ListNode* y= new ListNode (x);
            if(head==nullptr){
                head= y;
                tail=y;
            }
            else{
                tail->next= y;
                tail=y;
            }
         list2= list2->next;
        }
        }
        if(list1==nullptr&&list2!=nullptr){
            while(list2!=nullptr){
            ListNode *y= new ListNode (list2->val);
            if(head==nullptr){
                head= y;
                tail=y;
            }
            else{
                tail->next= y;
                tail=y;
            }
             list2= list2->next;
            }
        }
        else if(list1!=nullptr&&list2==nullptr){
            while(list1!=nullptr){
            ListNode* y= new ListNode (list1->val);
             if(head==nullptr){
                head= y;
                tail=y;
            }
            else{
                tail->next= y;
                tail=y;
            }
             list1= list1->next;
            }
        }
        return head;

    }
};
