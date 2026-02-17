/* Link list Node
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};*/
/*You are required to complete below method*/
Node * deleteAllOccurOfX(Node* head_ref, int x) {
       while(head_ref != nullptr && head_ref->data == x) {
           Node* temp = head_ref;
           head_ref = head_ref->next;
           delete temp;
       }
       Node* current = head_ref;
       Node* prev = nullptr;


       while(current != nullptr) {
           if(current->data == x) {
               prev->next = current->next;
               delete current;
               current = prev->next;
           } else {
               prev = current;
               current = current->next;
           }
       }
           return head_ref;
       }




Node* deleteAllOccurances(Node* head, int x) {
    // Your code here
    return deleteAllOccurOfX(head,x);
    
}