class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // i: pointer for the end of the valid portion in nums1.
        // j: pointer for the end of nums2.
        // k: pointer for the last position in nums1.
        int i = m - 1, j = n - 1, k = m + n - 1;

        // Merge nums1 and nums2 starting from the back.
        while (i >= 0 && j >= 0) {
            // Place the larger of the two elements at the end.
            if (nums1[i] > nums2[j])
                nums1[k--] = nums1[i--];
            else
                nums1[k--] = nums2[j--];
        }

        // If there are remaining elements in nums2, copy them.
        while (j >= 0)
            nums1[k--] = nums2[j--];
    }
};
