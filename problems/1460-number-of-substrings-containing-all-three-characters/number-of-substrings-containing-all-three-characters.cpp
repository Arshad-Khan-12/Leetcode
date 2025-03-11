class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> mpp;  // Map to store frequency of characters 'a', 'b', and 'c'
        int n = s.size();              // Length of the input string
        int ans = 0;                   // Variable to store the final answer (number of valid substrings)
        int l = 0, r = 0;              // Initialize left and right pointers for the sliding window

        // Expand the window with the right pointer
        while (r < s.size()) {
            mpp[s[r]]++;  // Increment frequency of current character

            // While current window contains at least one 'a', 'b', and 'c'
            while (mpp['a'] > 0 && mpp['b'] > 0 && mpp['c'] > 0) {
                // All substrings from current window's right boundary (r) to end of string are valid
                ans += (n - r);
                
                // Shrink the window from the left by reducing the frequency of s[l]
                mpp[s[l]]--;
                l++;  // Move left pointer forward
            }
            r++;  // Move right pointer forward to expand the window
        }
        
        return ans;  // Return the total count of valid substrings
    }
};
