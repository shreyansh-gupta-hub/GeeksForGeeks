// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
  public:
    vector<pair<int, int>> findPairs(Node* head, int k)
{
    // Write your code here.
    vector<pair<int, int>> ans;
    if(head == NULL || head->next == NULL) return ans;
    Node* right = head;
    while(right->next!=NULL){
        right = right->next;
    }
    Node* left = head;
    while (left != NULL && right != NULL && left != right && right->next != left){
        if(left->data + right->data == k){
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        }else if (left->data + right->data > k){
            right = right->prev;
        }else{
            left = left->next;
        }
    }
 
    return ans;
}

    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        // code here
        return findPairs(head,target);
    }
};