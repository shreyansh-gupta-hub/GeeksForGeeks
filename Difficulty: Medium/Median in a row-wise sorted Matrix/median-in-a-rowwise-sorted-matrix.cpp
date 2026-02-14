class Solution {
  public:
    int upperBound(vector<int> &arr, int x, int n) {
        int low = 0, high = n - 1;
        int ans = n;  

        while (low <= high) {
            int mid = (low + high) / 2;

            if (arr[mid] > x) {
                ans = mid;      
                high = mid - 1;   
            } else {
                low = mid + 1;   
            }
        }
        return ans;  
    }
    int countsmallequal(vector<vector<int>> &mat, int n, int m, int x){
        int count{0};
        for (int i{0};i<n;i++){
            count += upperBound(mat[i], x, m);
        }
        return count;
    }
    int median(vector<vector<int>> &mat) {
        // code here
        int n  = mat.size();
        int m = mat[0].size();
        int low = INT_MAX;
        int high = INT_MIN;
        for (int i{0}; i<n;i++){
            if(mat[i][0]<low) low = mat[i][0];
            if(mat[i][m-1]>high) high = mat[i][m-1];
        }
        int req = (n*m)/2;
        while(low<=high){
            int mid = low + (high-low)/2;
            int smallequal = countsmallequal(mat,n,m,mid);
            if(smallequal>req){
                high = mid-1;
            }else{
                low = mid +1;
            }
        }
        return low;
    }
};
