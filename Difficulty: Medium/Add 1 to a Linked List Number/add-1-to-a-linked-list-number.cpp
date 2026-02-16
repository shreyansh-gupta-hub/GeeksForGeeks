/*

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
    int addHelper(Node* temp){
        if(temp==NULL){
            return 1;
        }
        int carry = addHelper(temp->next);
        temp->data+=carry;
        if(temp->data<10){
            
            return 0;
        }
        temp->data = 0;
        return 1;
    }
    Node* addOne(Node* head) {
        // Your Code here
        int carry = addHelper(head);
        if(carry == 1){
            Node* newHead = new Node(1);
            newHead->data = 1;
            newHead->next = head;
            return newHead;
        }
        return head;
    }
};