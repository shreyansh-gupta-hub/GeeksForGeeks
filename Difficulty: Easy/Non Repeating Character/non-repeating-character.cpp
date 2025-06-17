
class Solution {
  public:
    char nonRepeatingChar(string &s) {
        // Your code here
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            bool found = false;
    
            for (int j = 0; j < n; ++j) {
                if (i != j && s[i] == s[j]) {
                    found = true;
                    break;
                }
            }
            if (!found) 
                return s[i];
        }
    
        return '$';
    }
};