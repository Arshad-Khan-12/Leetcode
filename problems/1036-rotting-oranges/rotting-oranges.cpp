class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0; // Count of fresh oranges

        // Collect all initially rotten oranges and count fresh ones.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2)
                    q.push({i, j});
                else if (grid[i][j] == 1)
                    fresh++;
            }
        }

        // If there are no fresh oranges, return 0.
        if (fresh == 0)
            return 0;

        int minutes = 0;
        // Directions: up, down, left, right.
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        // BFS to rot adjacent fresh oranges.
        while (!q.empty()) {
            int size = q.size();
            bool rottenOccurred =
                false; // Flag to check if any orange rotted in this minute.

            // Process all rotten oranges for this minute.
            for (int i = 0; i < size; i++) {
                auto [r, c] = q.front();
                q.pop();

                // Visit all 4 adjacent cells.
                for (auto& d : directions) {
                    int newR = r + d.first;
                    int newC = c + d.second;

                    // If within bounds and the orange is fresh.
                    if (newR >= 0 && newR < m && newC >= 0 && newC < n &&
                        grid[newR][newC] == 1) {
                        grid[newR][newC] = 2; // Rot the fresh orange.
                        q.push(
                            {newR,
                             newC}); // Add it to the queue for the next minute.
                        fresh--;     // Decrement the count of fresh oranges.
                        rottenOccurred =
                            true; // Mark that rotting occurred this minute.
                    }
                }
            }

            // If any orange rotted during this round, increment minutes.
            if (rottenOccurred)
                minutes++;
        }

        // If fresh oranges remain, return -1.
        return fresh > 0 ? -1 : minutes;
    }
};
