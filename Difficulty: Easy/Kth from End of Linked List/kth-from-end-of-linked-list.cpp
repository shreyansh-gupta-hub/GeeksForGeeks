/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

class Solution {
  public:
    int getKthFromLast(Node* head, int n) {
        Node* fast = head;
        Node* slow = head;
        if(head == NULL) return -1;
        for (int i{0};i<n;i++){
            if(fast==NULL) return -1;
            fast = fast->next;
            
        }
        if(fast==NULL) return head->data;
        while(fast!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
        return slow->data;
        
        
        
    }
};