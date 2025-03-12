class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos=0;
        int neg = 0;
        int low=0;
        int n=nums.size();
        int high = n-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] > 0){
                high = mid-1;
            }
            else{
                low=mid+1;
            }
        }
        pos = n-low;
        low=0;
        high = n-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] < 0){
                low = mid+1;
            }
            else{
                high=mid-1;
            }
        }
        neg=low;
        // return neg;
        return pos>neg?pos:neg;
    }
};