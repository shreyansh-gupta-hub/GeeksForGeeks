// User function template for C++
class Solution {
  public:
    bool matSearch(vector<vector<int>> &arr, int target) {
        // your code here
        int n1 = arr.size();
        int n2 = arr[0].size();
        pair<int,int> req = {0,n2-1};
        while(req.first<n1 && req.second>=0){
            if(arr[req.first][req.second] == target){
                return true;
            }else if(arr[req.first][req.second]>target){
                req.second--;
            }else{
                req.first++;
            }
        }
        return false;
    }
};