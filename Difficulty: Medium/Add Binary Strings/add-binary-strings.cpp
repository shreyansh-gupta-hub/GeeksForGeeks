// User function template for C++
class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        // your code here
    size_t firstOne1 = s1.find('1');
    s1 = (firstOne1 == string::npos) ? "0" : s1.substr(firstOne1);

    size_t firstOne2 = s2.find('1');
    s2 = (firstOne2 == string::npos) ? "0" : s2.substr(firstOne2);

    int n = s1.size();
    int m = s2.size();

    if (n < m) {
        return addBinary(s2, s1);
    }

    int j = m - 1;
    int carry = 0;

    for (int i = n - 1; i >= 0; i--) {
        int bit1 = s1[i] - '0';
        int sum = bit1 + carry;

        if (j >= 0) {
            int bit2 = s2[j] - '0';
            sum += bit2;
            j--;
        }

        int bit = sum % 2;
        carry = sum / 2;
        s1[i] = (char)(bit + '0');
    }

    if (carry > 0) {
        s1 = '1' + s1;
    }

    return s1;
    }
};