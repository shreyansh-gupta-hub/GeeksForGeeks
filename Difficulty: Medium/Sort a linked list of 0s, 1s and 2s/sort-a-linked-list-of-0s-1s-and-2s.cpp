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
    // Write your code here.
    int count1{0};
    int count2{0};
    int count0{0};
    if (head ==NULL || head->next == NULL) return head;
    Node* temp = head;
    while(temp!=NULL){
        int x = temp->data;
        if(x==0) count0++;
        else if (x==1) count1++;
        else count2++;
        temp = temp->next;
    }
    temp = head;
    for (int i{0}; i<count0;i++){
        if(temp!=NULL){temp->data = 0;
        temp = temp->next;}
    }
    for (int i{0}; i<count1;i++){
            if(temp!=NULL){temp->data = 1;
            temp = temp->next;}
        }
    for (int i{0}; i<count2;i++){
            if (temp!=NULL){temp->data = 2;
            temp = temp->next;}
        }
    return head;

    }
    Node* segregate(Node* head) {
        // code here
        return sortList(head);
        
    }
};