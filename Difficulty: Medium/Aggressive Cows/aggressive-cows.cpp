class Solution {
  public:
    bool canweplace(vector<int> &stalls, int k,int dist){
      int cntcows = 1;
      int last = stalls[0];
      for (int i{0}; i<stalls.size();i++){
          if(stalls[i]-last>=dist){
              cntcows++;
              last = stalls[i];
          }
      }
      if(cntcows>=k) return true;
      return false;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        sort(stalls.begin(), stalls.begin() + stalls.size());
        int ans{-1};
        int low{0};
        int high = stalls[stalls.size()-1]-stalls[0];
        while(low<=high){
            int mid = low + (high-low)/2;
            if(canweplace(stalls,k,mid)==true){
                ans = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return ans;
        
    }
};