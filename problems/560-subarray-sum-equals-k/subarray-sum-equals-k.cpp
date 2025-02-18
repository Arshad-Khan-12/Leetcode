class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        int sum = 0;
        mpp[0]=1;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(mpp.count(sum-k)){
                ans+=mpp[sum-k];
            }
            mpp[sum]++;
        }
        return ans;
    }
};