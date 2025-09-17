#include <cmath>
class Solution {
  public:
    vector<int> divFloorCeil(int a, int b) {
        // code here
        int r = a/b;
        int f = a/b;
        vector<int> q;
        if ((a^b) < 0 && a%b!=0){
            r--;
        }else if ((a^b)>0 && a%b!=0){
            f++;
        }
        q.push_back(r);
        q.push_back(f);
        return q;
    }
};