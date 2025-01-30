class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n + 1);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        // Check if all components are bipartite
        vector<int> color(n + 1, -1);
        vector<bool> visited(n + 1, false);
        bool is_bipartite = true;
        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) {
                queue<int> q;
                q.push(i);
                color[i] = 0;
                visited[i] = true;
                while (!q.empty() && is_bipartite) {
                    int u = q.front();
                    q.pop();
                    for (int v : adj[u]) {
                        if (!visited[v]) {
                            visited[v] = true;
                            color[v] = color[u] ^ 1;
                            q.push(v);
                        } else {
                            if (color[v] == color[u]) {
                                is_bipartite = false;
                                break;
                            }
                        }
                    }
                }
                if (!is_bipartite) break;
            }
        }
        if (!is_bipartite) return -1;
        
        // Process each component to find maximum groups
        vector<bool> visited2(n + 1, false);
        int total = 0;
        for (int i = 1; i <= n; ++i) {
            if (!visited2[i]) {
                // Collect all nodes in this component
                vector<int> component;
                queue<int> q;
                q.push(i);
                visited2[i] = true;
                component.push_back(i);
                while (!q.empty()) {
                    int u = q.front();
                    q.pop();
                    for (int v : adj[u]) {
                        if (!visited2[v]) {
                            visited2[v] = true;
                            component.push_back(v);
                            q.push(v);
                        }
                    }
                }
                
                // Compute maximum depth for this component
                int max_depth = 0;
                for (int u : component) {
                    vector<int> level(n + 1, -1);
                    queue<int> q_bfs;
                    q_bfs.push(u);
                    level[u] = 0;
                    int current_max = 0;
                    while (!q_bfs.empty()) {
                        int x = q_bfs.front();
                        q_bfs.pop();
                        for (int v : adj[x]) {
                            if (level[v] == -1) {
                                level[v] = level[x] + 1;
                                current_max = max(current_max, level[v]);
                                q_bfs.push(v);
                            }
                        }
                    }
                    max_depth = max(max_depth, current_max);
                }
                total += (max_depth + 1);
            }
        }
        return total;
    }
};