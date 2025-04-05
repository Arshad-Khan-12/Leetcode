class Solution {
    int total = 0; // Cumulative sum of all subset XOR totals.
public:
    // Recursive helper function for backtracking through subsets.
    void dfs(int idx, int n, int xorVal, vector<int>& nums) {
        // Base case: All elements have been processed.
        if (idx >= n) {
            total += xorVal; // Add the XOR total of this subset.
            return;
        }
        
        // Option 1: Include nums[idx] in the subset (update the XOR value).
        dfs(idx + 1, n, xorVal ^ nums[idx], nums);
        
        // Option 2: Exclude nums[idx] and move to the next element.
        dfs(idx + 1, n, xorVal, nums);
    }
    
    int subsetXORSum(vector<int>& nums) {
        // Start the DFS from index 0 with an initial XOR value of 0.
        dfs(0, nums.size(), 0, nums);
        return total; // Return the cumulative sum of XOR totals.
    }
};
