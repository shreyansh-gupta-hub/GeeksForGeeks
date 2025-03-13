//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
public:
    int pairWithMaxSum(vector<int> &arr) {
        int n = arr.size();
        if (n < 2) return -1; 
        
        int max_sum = INT_MIN;
        
        for (int i = 0; i < n - 1; i++) {
            int curr_sum = arr[i] + arr[i + 1];
            max_sum = max(max_sum, curr_sum);
        }
        
        return max_sum;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        cout << ob.pairWithMaxSum(nums) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends