class Solution {
  public:
    void solve(int idx, int k, int n, int sum, vector<int>& temp,vector<vector<int>>& res) {  
        if (sum == n && k == 0) {
            res.push_back(temp);
            return; 
        }    
        for (int i = idx; i <= 9; i++) {
            temp.push_back(i);
            solve(i + 1, k - 1, n, sum + i, temp,res);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(int n, int k) {
        vector<vector<int>> res;
        vector<int> temp;
        solve(1, k, n, 0, temp, res);
        return res;
    }
};