
// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        // Code Here
        int max{0};
        int secondmax{-1};
        for (auto i:arr){
            if (i>max){
                max = i;
            }
        }
        for (auto i:arr){
            if(i>secondmax && max!=i){
                secondmax=i;
            }
        }
        return secondmax;
    }
};

