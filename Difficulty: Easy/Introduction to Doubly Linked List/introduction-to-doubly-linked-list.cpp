// User function Template for C++

/*
class Node{
public:
    Node* prev;
    int data;
    Node* next;`

    Node()
    {
        prev = NULL;
        data = 0;
        next = NULL;
    }

    Node(int value)
    {
        prev = NULL;
        data = value;
        next = NULL;
    }
};*/

class Solution {
  public:
    Node* constructDLL(vector<int>& arr) {
        int n = arr.size();
        Node* head = new Node(arr[0]);
        Node* back = head;
        for(int i{1}; i<n; i++){
            Node* temp = new Node(arr[i]);
            temp->prev=back;
            back->next = temp;
            back=temp;
            
        }
        return head;
    }
};