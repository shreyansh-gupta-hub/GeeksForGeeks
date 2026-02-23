class Solution {
  public:
    void reverseStk(stack<int>& st, queue<int>& q){
        if(st.empty()) return;
        int x = st.top();
        q.push(x);
        st.pop();
        reverseStk(st,q);
        st.push(q.front());
        q.pop();
        return;
    }
    void reverseStack(stack<int> &st) {
        // code here
        queue<int> q;
        reverseStk(st,q);
    }
};