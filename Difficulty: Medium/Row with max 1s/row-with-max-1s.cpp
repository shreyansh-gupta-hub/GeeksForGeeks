// User function template for C++
class Solution {
  public:
    int lowerbound(vector<int> &arr, int n1){
        int low = 0;
        int high = n1-1;
        int ans = n1;
        while(low<=high){
            int mid = low + (high-low)/2;
            //mabye an answer
            if(arr[mid]>=1){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int n1 = arr[0].size();
        int n2 = arr.size();
        int maxidx{-1};
        int max = 0;
        
        for (int i{0};i<n2;i++){
            if(arr[i][0] == 1) return i;
            if (arr[i][n1-1] == 0) continue;
            int sum = n1 - lowerbound(arr[i],n1);
            if(sum>max){
                    max = sum;
                    maxidx = i;
                }
        }
        
        return maxidx;
    }
};