/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  public:
    Node* merge(Node* list1,Node* list2){
        Node* DummyNode = new Node(-1);
        Node* res = DummyNode;
        while(list1!=NULL && list2!=NULL){
            if(list1->data<list2->data){
                res->bottom = list1;
                res = list1;
                list1 = list1->bottom;
            }else{
                res->bottom = list2;
                res = list2;
                list2 = list2->bottom;
            }
            res->next = NULL;
        }
        if(list1) res->bottom = list1;
        if(list2) res->bottom = list2;
        return DummyNode->bottom;
    }
    Node *flatten(Node *head) {
        // code here
        if(head == NULL || head->next == NULL) return head;
        Node* merged_head = flatten(head->next);
        return merge(head,merged_head);
        
        
    }
};