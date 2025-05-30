/* Structure of Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        if (!head) return nullptr;

        if (x == 1) {
            Node* temp = head;
            head = head->next;
            if (head) head->prev = nullptr;
            delete temp;
            return head;
        }

        Node* curr = head;
        int count = 1;

        while (curr && count < x) {
            curr = curr->next;
            count++;
        }

        if (!curr) return head;

        if (curr->prev) curr->prev->next = curr->next;
        if (curr->next) curr->next->prev = curr->prev;

        delete curr;
        return head;
    }
};