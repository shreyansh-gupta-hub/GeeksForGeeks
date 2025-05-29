/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

// Function to insert a new node at given position in doubly linked list.
class Solution {
  public:
    // Function to insert a new node at given position in doubly linked list.
    Node *addNode(Node *head, int pos, int data) {
        Node* current = head;
        int count = 0;

        // Traverse to the pos-th node
        while (current != NULL && count < pos) {
            current = current->next;
            count++;
        }

        // Create the new node
        Node* newNode = new Node(data);

        // Adjust the links to insert after current
        newNode->next = current->next;
        newNode->prev = current;

        if (current->next != NULL) {
            current->next->prev = newNode;
        }

        current->next = newNode;

        return head;
    }
};