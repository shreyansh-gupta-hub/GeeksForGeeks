class Solution {
  public:
    int myAtoi(char *s) {
        int i = 0;
        long ans = 0;
        int sign = 1;

        while (s[i] == ' ') i++;

        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+') {
            i++;
        }

        while (isdigit(s[i])) {
            ans = ans * 10 + (s[i] - '0');
            if (sign == 1 && ans > INT_MAX) return INT_MAX;
            if (sign == -1 && -ans < INT_MIN) return INT_MIN;
            i++;
        }

        return sign * ans;
    }
};