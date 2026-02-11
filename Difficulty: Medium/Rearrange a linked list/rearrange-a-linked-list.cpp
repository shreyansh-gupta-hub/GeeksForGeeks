/* Node structure

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

class Solution {
  public:
    void rearrangeEvenOdd(Node *head) {
        if(head==NULL ||head->next == NULL) return;
        Node* odd = head;
        Node* even = head->next;
        Node* evenhead = even;
        while(even != NULL && even->next != NULL){
            odd->next=odd->next->next;
            even->next=even->next->next;

            odd= odd->next;
            even = even->next;
        }
        odd->next = evenhead;
    
        
    }
};