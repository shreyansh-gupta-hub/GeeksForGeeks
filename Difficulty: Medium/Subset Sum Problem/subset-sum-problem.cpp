class Solution {
  public:
    bool solve(vector<int>& arr, int sum, int ind, int k, vector<vector<int>>& dp){
        if (k==sum) return true;
        if(ind==arr.size()) return false;
        if(dp[ind][k]!=-1) return dp[ind][k];
        //pick 
        bool pick = false;
        if (k + arr[ind] <= sum){
            pick = solve(arr,sum,ind+1,k+arr[ind],dp);
            if (pick) dp[ind][k] = 1;
            if (pick) return true;
        }
        //not pick
        bool notPick = solve(arr,sum,ind+1,k,dp);
        dp[ind][k]=notPick||pick;
        return dp[ind][k];
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        vector<vector<int>> dp(arr.size(), vector<int>(sum + 1, -1));
        return solve(arr,sum,0,0,dp);
    }
};