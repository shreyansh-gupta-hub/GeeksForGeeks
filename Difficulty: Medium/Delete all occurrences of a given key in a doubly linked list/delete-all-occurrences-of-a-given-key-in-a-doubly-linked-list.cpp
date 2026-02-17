/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
}; */

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        // code here
        if(head_ref == NULL || *head_ref == NULL) return;
        Node* temp = *head_ref;
        while(temp!=NULL){
            Node* nextNode = temp->next;
            if(temp->data == x) {
                if(temp->prev)
                    temp->prev->next = temp->next;
                else
                    *head_ref = temp->next; 
                if(temp->next)
                    temp->next->prev = temp->prev;
                delete temp;
            }
            temp = nextNode;
            
        }
    }
    
};