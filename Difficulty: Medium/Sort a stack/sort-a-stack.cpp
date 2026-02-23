class Solution {
  public:
    void sorted(stack<int> &st, int n){
        if(n<=1) return;
        int TopElement = st.top();
        st.pop();
        sorted(st,n-1);
        stack<int> dummy;
        while(!st.empty() && st.top()>TopElement){
            dummy.push(st.top());
            st.pop();
        }
        st.push(TopElement);
        while(!dummy.empty()){
            st.push(dummy.top());
            dummy.pop();
        }
        return;
    }
    void sortStack(stack<int> &st) {
        // code here
        sorted(st,st.size());
        
    }
};
