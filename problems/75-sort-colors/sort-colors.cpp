class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0;
        int high = nums.size() - 1;
        
        // Process elements until mid surpasses high.
        while (mid <= high) {
            // If the current element is 0, swap it to the beginning.
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            // If the current element is 2, swap it to the end.
            else if (nums[mid] == 2) {
                swap(nums[mid], nums[high]);
                high--;
            }
            // If the current element is 1, just move to the next element.
            else {
                mid++;
            }
        }
    }
};
