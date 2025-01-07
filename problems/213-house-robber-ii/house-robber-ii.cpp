class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return nums[0]>nums[1] ? nums[0] : nums[1];
        int prev1=nums[0];
        int prev2=0;
        for(int i=1;i<n-1;i++){
            int take=nums[i];
            if(i>1){

             take += prev2;
            }

            int notTake = prev1;
            int cur=max(take,notTake);

            prev2=prev1;
            prev1=cur;


        }
        int ans1=prev1;


        prev1=nums[1];
        prev2=0;

        for(int i=2;i<n;i++){
            int take=nums[i];
            if(i>1){

             take += prev2;
            }

            int notTake = prev1;
            int cur=max(take,notTake);

            prev2=prev1;
            prev1=cur;


        }

        int ans2=prev1;
        return max(ans1,ans2);
    }
};