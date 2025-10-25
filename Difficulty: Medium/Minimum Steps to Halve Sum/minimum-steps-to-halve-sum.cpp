class Solution {
  public:
    int minOperations(vector<int>& arr) {
        double totalSum = 0;
        for (auto x : arr) totalSum += x;

        double target = totalSum / 2.0;
        double currSum = totalSum;

        priority_queue<double> pq;
        for (auto x : arr) pq.push(x);

        int operations = 0;

        while (currSum > target) {
            double top = pq.top();
            pq.pop();

            double reduced = top / 2.0;
            currSum -= reduced;
            pq.push(reduced);

            operations++;
        }

        return operations;
    }
};