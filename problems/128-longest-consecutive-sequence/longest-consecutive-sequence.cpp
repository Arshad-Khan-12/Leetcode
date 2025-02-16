class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int maxLen = 0;
        for (int num : numSet) {
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int currentLen = 1;
                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    currentLen++;
                }
                maxLen = max(maxLen, currentLen);
            }
        }
        return maxLen;
    }
};