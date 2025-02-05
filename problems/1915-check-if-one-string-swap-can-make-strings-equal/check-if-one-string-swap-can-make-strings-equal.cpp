class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        // Vector to store the indices of mismatched characters
        vector<int> mismatch;

        // Traverse the strings and find mismatched positions
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                mismatch.push_back(i);
            }
        }

        // If no mismatches, the strings are already equal
        if (mismatch.size() == 0) return true;

        // If there are exactly 2 mismatches, check if swapping makes them equal
        if (mismatch.size() == 2) {
            int i = mismatch[0], j = mismatch[1];
            return s1[i] == s2[j] && s1[j] == s2[i];
        }

        // If there are more than 2 mismatches, one swap cannot make them equal
        return false;
    }
};
