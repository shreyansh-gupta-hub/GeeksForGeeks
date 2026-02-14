/* Link list node
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
}; */

class Solution {
  public:
    Node* mergeLists(Node* list1, Node* list2) {
        Node* dummy = new Node(-1);
        Node* temp = dummy;

        while(list1 != NULL && list2 != NULL) {
            if(list1->data < list2->data) {
                temp->next = list1;
                temp = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                temp = list2;
                list2 = list2->next;
            }
        }

        if(list1) temp->next = list1;
        else temp->next = list2;

        return dummy->next;
    }


    Node* middleNode(Node* head) {
        Node* slow = head;
        Node* fast = head->next;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }


    Node* sortList(Node* head) {
        if(head == NULL || head->next == NULL) return head;

        Node* middle = middleNode(head);
        Node* leftHead = head;
        Node* rightHead = middle->next;
        middle->next = NULL;

        leftHead = sortList(leftHead);
        rightHead = sortList(rightHead);

        return mergeLists(leftHead, rightHead);
    }

    Node* insertionSort(Node* head_ref) {
        return sortList(head_ref);
    }
};
