class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        // Sort the meetings based on their start times.
        sort(meetings.begin(), meetings.end());

        // Merge overlapping meetings.
        vector<vector<int>> m2;
        m2.push_back(meetings[0]);
        for (int i = 1; i < meetings.size(); i++) {
            // If the current meeting overlaps with the last merged meeting,
            // update the end time.
            if (meetings[i][0] <= m2.back()[1]) {
                m2.back()[1] = max(m2.back()[1], meetings[i][1]);
            } else {
                // Otherwise, add this meeting as a new interval.
                m2.push_back(meetings[i]);
            }
        }

        int ans = 0;
        // Count free days before the first meeting.
        ans += m2[0][0] - 1;

        // Count free days between merged meetings.
        for (int i = 1; i < m2.size(); i++) {
            ans += (m2[i][0] - m2[i - 1][1] - 1);
        }

        // Count free days after the last meeting.
        ans += (days - m2.back()[1]);

        return ans;
    }
};
