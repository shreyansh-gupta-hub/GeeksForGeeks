class Solution {
  public:
    vector<string> AllPossibleStrings(string s) {
        // Code here
        int n = s.length();
        vector<string> ans;
        for (int i = 1; i < (1 << n); i++) { 
            string sub = "";
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) sub += s[j];
            }
            ans.push_back(sub);  
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};