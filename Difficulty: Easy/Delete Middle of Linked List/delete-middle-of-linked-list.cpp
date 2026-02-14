/* Link list Node:

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

// Deletes middle of linked list and returns head of the modified list
class Solution {
  public:
    Node* deleteMid(Node* head){
        Node* fast = head;
        Node* slow = head;
        if(head == NULL || head->next  == NULL) return NULL;
        if (head->next->next  == NULL){
            head->next=NULL;
            return head;
        };
        if(fast->next==NULL || fast->next->next==NULL ){
            Node* newhead = head->next;
            return newhead;
        }
        fast = fast->next->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        slow->next = slow->next->next;
        return head;
    }

};