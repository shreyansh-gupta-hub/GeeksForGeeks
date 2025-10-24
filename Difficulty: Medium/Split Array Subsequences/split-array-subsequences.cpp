class Solution {
  public:
    bool isPossible(vector<int>& arr, int k) {
        auto comp = [](pair<int,int> a, pair<int,int> b) {
        if(a.first == b.first)
            return a.second > b.second; 
        return a.first > b.first;       
    };
    priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> pq(comp);

    int i = 0;
    while(i < arr.size()) {
        if(pq.empty()) {
            pq.push({arr[i], 1});
            i++;
        }
        else {
            auto top = pq.top();
            if(arr[i] == top.first) {
                pq.push({arr[i], 1});
                i++;
            }
            else if(arr[i] == top.first + 1) {
                pq.pop();
                pq.push({arr[i], top.second + 1});
                i++;
            }
            else {
                if(top.second < k) return false;
                pq.pop();
            }
        }
    }
    while(!pq.empty()) {
        if(pq.top().second < k) return false;
        pq.pop();
    }
    }
};
