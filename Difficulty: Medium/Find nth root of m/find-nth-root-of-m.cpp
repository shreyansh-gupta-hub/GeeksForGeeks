class Solution {
  public:
long long power(long long base, int exp, int limit) {
        long long ans = 1;
        for (int i = 0; i < exp; i++) {
            ans *= base;
            if (ans > limit) return ans;
        }
        return ans;
    }

    int nthRoot(int n, int m) {
        if (m == 0) return 0; 
        int low = 1, high = m;

        while (low <= high) {
            
            int mid = low + (high - low) / 2;
            long long val = power(mid, n, m);

            if (val == m) return mid;
            if (val > m) high = mid - 1;
            else low = mid + 1;
        }
        return -1;
    }
};