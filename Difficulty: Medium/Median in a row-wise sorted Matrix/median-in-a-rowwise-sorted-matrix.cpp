class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        int n  = mat.size();
        int m = mat[0].size();
        vector<int> arr;
        for (auto i : mat){
            for(auto j: i){
                arr.push_back(j);
            }
        }
        sort(arr.begin(),arr.end());
        int len = arr.size();
        len /=2;
        return arr[len];
        
    }
};
