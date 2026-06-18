/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mpp;
        mpp[NULL]= NULL;
        Node* curr=head;
        while(curr!=nullptr){
            Node* node2 = new Node(curr->val);
            mpp[curr]= node2;
            curr= curr->next;
        }
        curr=head;
        while(curr!=nullptr){
                Node* node2= mpp[curr];
                node2->next= mpp[curr->next];
                node2->random= mpp[curr->random];
                curr= curr->next;
        }


        return mpp[head];


    }
};
