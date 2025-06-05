/*
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int findlength(Node* fast,Node* slow){
        int cnt {1};
        fast= fast->next;
        while (fast!=slow){
            cnt++;
            fast= fast->next;
        }
        return cnt++;
    }
    int countNodesinLoop(Node *head) {
        // Code here
        Node* slow = head;
        Node* fast= head;
        while(fast!=NULL && fast->next!=NULL){
            slow= slow->next;
            fast=fast->next->next;
            if(fast==slow){
                return findlength(fast, slow);
            }
        }
        return 0;
    }
};