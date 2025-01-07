class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> count;  // To store the frequency of prefix sums
        
        int curr_sum = 0;  // Current prefix sum
        int total_subarrays = 0;  // Total number of valid subarrays

        // Iterate through the array
        for (int num : nums) {
            curr_sum += num&1;  // Update the current prefix sum
            if(curr_sum == k){
                total_subarrays++;
            }
            // Check if there is a prefix sum such that curr_sum - k exists in the map
            if (count.find(curr_sum - k) != count.end()) {
                total_subarrays += count[curr_sum - k];  // Add the number of such prefix sums
            }

            // Increment the frequency of the current prefix sum
            count[curr_sum]++;
        }

        return total_subarrays;  // Return the total number of subarrays with the given sum
    }
};