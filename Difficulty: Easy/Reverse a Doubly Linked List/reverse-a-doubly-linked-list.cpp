/*
class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/
class Solution {
  public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
        // Your code here
        if (head == NULL || head->next == NULL) return head;
        DLLNode* last = NULL;
        DLLNode* current = head;
        while(current!=NULL){
            last = current->prev;
            current->prev = current->next;
            current->next = last;
            current = current->prev;
        }
        return last->prev;
    }
};