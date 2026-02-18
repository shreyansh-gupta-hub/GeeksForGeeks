// User function Template for C++
class Solution {
  public:
    long long int bitsAreInAltOrder(long long int n) {
        // code here
        unsigned int x = n ^ (n >> 1);
        if((x & (x + 1))==0) return 1;
        return 0;
    }
};