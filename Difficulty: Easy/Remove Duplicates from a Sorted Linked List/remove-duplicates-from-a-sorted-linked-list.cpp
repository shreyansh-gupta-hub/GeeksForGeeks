/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

class Solution {
  public:
    Node* deleteDuplicates(Node* head) {
        if(head==NULL || head->next==NULL) return head;
        Node* curr  = head;
        while(curr!=NULL && curr->next!=NULL){
            if(curr->next->data == curr->data){
                curr->next = curr->next->next;
            }else{
                curr = curr->next;
            }
        }
        return head;
    }
    Node* removeDuplicates(Node* head) {
        return deleteDuplicates(head);
        // code here
        
    }
};