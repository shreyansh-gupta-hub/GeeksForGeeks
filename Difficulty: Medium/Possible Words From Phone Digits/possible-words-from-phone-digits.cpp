class Solution {
public:

void comb(vector<string> &st, int index, vector<int> &digits,
          string test, vector<string> &result) {
    
    if (index == digits.size()) {
        result.push_back(test);
        return;
    }

    int digit = digits[index];

    // Skip digits 0 and 1
    if (digit == 0 || digit == 1) {
        comb(st, index + 1, digits, test, result);
        return;
    }

    string letters = st[digit];

    for (int i = 0; i < letters.size(); i++) {
        comb(st, index + 1, digits, test + letters[i], result);
    }
}

    vector<string> possibleWords(vector<int> &arr) {
    
        vector<string> st = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
    
        vector<int> digits;
        for (int d : arr) {
            if (d > 1) digits.push_back(d);
        }
    
        if (digits.empty()) return {};
    
        vector<string> result;
        comb(st, 0, digits, "", result);
    
        return result;
    }
};