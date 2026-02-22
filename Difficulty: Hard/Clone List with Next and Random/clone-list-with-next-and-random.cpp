/*
class Node {
  public:
    int data;
    Node* next;
    Node* random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
  public:
Node* cloneLinkedList(Node* head) {
        if(head==NULL) return head;
        //i'm gonna insert new nodes inbetween
        Node* temp = head;
        while(temp!=NULL){
            Node* newNode = new Node(-1);
            newNode->next = temp->next;
            newNode->data = temp->data;
            temp->next = newNode;
            temp = temp->next->next;
        }

        //now connect random ptr
        temp = head;
        while(temp!=NULL){
            Node* nextptr = temp->next;
            if(temp->random!=NULL){
                nextptr->random = temp->random->next;
            }else{
                nextptr->random = NULL;
            }
            temp = temp->next->next;
        }

        //now connect next node
        temp = head;
        Node* DummyNode = new Node(-1);
        DummyNode->next = temp->next;
        Node* res = DummyNode;
        while(temp!=NULL){
            res->next = temp->next;
            temp->next = temp->next->next;
            temp = temp->next;
            res = res->next;
        }

        return DummyNode->next;
        
    }
};