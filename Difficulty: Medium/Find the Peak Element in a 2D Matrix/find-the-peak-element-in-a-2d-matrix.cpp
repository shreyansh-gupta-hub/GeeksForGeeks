class Solution {
  public:
    int maxrow(vector<vector<int>>& mat, int n, int col){
        int maxValue = mat[0][col];
        int index = 0;
        for(int i = 1; i < n; i++){
            if(mat[i][col] > maxValue){
                maxValue = mat[i][col];
                index = i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
    
        int low = 0, high = m - 1;
    
        while(low <= high){
            int mid = (low + high) / 2;
    
            int maxi = 0;
            for(int i = 1; i < n; i++){
                if(mat[i][mid] > mat[maxi][mid]){
                    maxi = i;
                }
            }
    
            int left = (mid - 1 >= 0) ? mat[maxi][mid - 1] : INT_MIN;
            int right = (mid + 1 < m) ? mat[maxi][mid + 1] : INT_MIN;
    
            if(mat[maxi][mid] >= left && mat[maxi][mid] >= right)
                return {maxi, mid};
            else if(mat[maxi][mid] < left)
                high = mid - 1;
            else
                low = mid + 1;
        }
    
        return {-1, -1};
    }
    
};
