class Solution {
  public:
    int shortCycle(int V, vector<vector<int>>& edges) {
        // Build adjacency list
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        int ans = INT_MAX;
        
        // Run BFS from each vertex
        for (int i = 0; i < V; i++) {
            vector<int> dist(V, -1);
            vector<int> parent(V, -1);
            queue<int> q;
            
            dist[i] = 0;
            q.push(i);
            
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                
                for (int neigh : adj[node]) {
                    if (dist[neigh] == -1) {
                        // Not visited
                        dist[neigh] = dist[node] + 1;
                        parent[neigh] = node;
                        q.push(neigh);
                    } 
                    else if (parent[node] != neigh) {
                        // Found a cycle
                        ans = min(ans, dist[node] + dist[neigh] + 1);
                    }
                }
            }
        }
        
        return (ans == INT_MAX) ? -1 : ans;
    }
};

