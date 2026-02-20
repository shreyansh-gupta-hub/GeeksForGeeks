/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
        Node* reverse(Node*& head, Node* temp, int x){
        Node* sve = temp;
        Node* curr = temp;
        Node* prev = NULL;
        for (int i{0};i<x;i++){
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        if(temp == head){
            head = prev;
        }
        sve->next = curr;
        
        return prev;
    }
    Node* reverseKGroup(Node* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        Node* temp = head;
        Node* prevGroupTail = NULL;
        Node* nextGroupStart = NULL;
        while(temp!=NULL){
           Node* check = temp;
            int count = 0;
            while(count < k && check){
                check = check->next;
                count++;
            }
            if(count == k){
                Node* newGroupHead = reverse(head, temp, k);
                if(prevGroupTail){
                    prevGroupTail->next = newGroupHead;
                }
                prevGroupTail = temp;
                temp = temp->next;
            }else if(count > 0){
                Node* curr = temp;
                Node* prev = NULL;
                while(curr){
                    Node* next = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = next;
                }
                if(prevGroupTail){
                    prevGroupTail->next = prev;
                }

                break;
            }
        }

        return head;
    }
};