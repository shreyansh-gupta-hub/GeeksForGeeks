/*
class Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    pair<int,Node*> SizeofLL(Node* head){
        Node* temp = head;
        int count{0};
        while(temp->next!=NULL){
            temp = temp->next;
            count++;
        }
        count++;
        return {count, temp};
    }
    Node* rotateLL(Node* head,int cnt){
        int count = 1;
        Node* temp =head;
        while(count < cnt){
            temp = temp->next;
            count++;
        }
        
        return temp;
    }
    Node* rotate(Node* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        pair<int,Node*> res= SizeofLL(head);
        int LLSize = res.first;
        Node* EndNode =res.second;
        k%=LLSize;
        if(k==0) return head;
        EndNode->next = head;
        
        Node* newTail = rotateLL(head, k);
        Node* newHead = newTail->next;
        newTail->next=NULL;
        head = newHead;
        return head;
    }
};