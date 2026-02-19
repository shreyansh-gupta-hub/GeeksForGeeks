/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};
*/

class Solution {
  public:

    Node *removeDuplicates(struct Node *head) {
        // Your code here
        if(head == NULL || head->next==NULL) return head;
        Node* temp = head;
        while(temp!=NULL && temp->next!=NULL){
            if(temp->prev!=NULL && temp->prev->data == temp->data && temp->prev->prev !=NULL) {
                Node* delNode = temp->prev;
                temp->prev->prev->next = temp;
                temp->prev = temp->prev->prev;
                delete delNode;
            }else if (temp->prev !=NULL && temp->prev->data == temp->data && temp->prev->prev ==NULL){
                Node* delNode = temp->prev;
                temp->prev = NULL;
                Node* newhead = temp;
                head = newhead;
                delete delNode;
            }
            
            
            if(temp->next->data == temp->data && temp->next->next !=NULL){
                Node* delNode = temp->next;
                temp->next->next->prev = temp;
                temp->next = temp->next->next;
                
                delete delNode;
            }else if (temp->next->data == temp->data && temp->next->next ==NULL){
                Node* delNode = temp->next;
                temp->next = NULL;
                delete delNode;
            }
            temp = temp->next;
        }
        return head;
    }
};