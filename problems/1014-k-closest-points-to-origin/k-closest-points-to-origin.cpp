class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> hp;
        for (int i = 0; i < points.size(); i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];

            int dis = x1 * x1 + y1 * y1; // Use squared distance
            hp.push({dis, {points[i][0], points[i][1]}});
            if (hp.size() > k) {
                hp.pop(); // Keep the heap size to k
            }
        }
        vector<vector<int>> ans;
        while (!hp.empty()) {
            ans.push_back({hp.top().second.first, hp.top().second.second});
            hp.pop();
        }
        return ans;
    }
};