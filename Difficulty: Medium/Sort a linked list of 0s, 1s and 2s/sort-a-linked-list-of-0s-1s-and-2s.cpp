/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:

    Node* sortList(Node *head){
    // Write your code here.\
    if (head ==NULL || head->next == NULL) return head;

    Node* oneDummy = new Node(-1);
    Node* twoDummy = new Node(-1);
    Node* zeroDummy = new Node(-1);

    Node* zeroTail = zeroDummy;
    Node* oneTail = oneDummy;
    Node* twoTail = twoDummy;


    Node* temp = head;
    while(temp!=NULL){
        int x = temp->data;
        if(x==0){
            zeroTail->next = temp;
            zeroTail = zeroTail->next;
        } 
        else if (x==1){
            oneTail->next = temp;
            oneTail = oneTail->next;            
        }
        else{
            twoTail->next = temp;
            twoTail = twoTail->next;            
        }
        temp = temp->next;
    }
    
    zeroTail->next = oneDummy->next ? oneDummy->next : twoDummy->next;
    oneTail->next = twoDummy->next;
    twoTail->next = nullptr;
    head = zeroDummy->next;
    delete zeroDummy;
    delete oneDummy;
    delete twoDummy;
    return head;

    }
    Node* segregate(Node* head) {
        // code here
        return sortList(head);
        
    }
};