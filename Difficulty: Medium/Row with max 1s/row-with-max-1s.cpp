// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int n1 = arr[0].size();
        int n2 = arr.size();
        int maxidx{-1};
        int max = INT_MIN;
        
        for (int i{0};i<n2;i++){
            int sum{0};
            if(arr[i][0] == 1) return i;
            if (arr[i][n1-1] == 0) continue;
            for(int j{0}; j<n1-1;j++){
                if(arr[i][j]==1){
                    sum++;
                }
                
            }
            if(sum>max){
                    max = sum;
                    maxidx = i;
                }
        }
        
        return maxidx;
    }
};