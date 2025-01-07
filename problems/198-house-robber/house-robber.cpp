class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>ans(nums.size()+1,-1);
        ans[0]=nums[0];
        if(nums.size()==1) return nums[0];
        ans[1]=max(ans[0],nums[1]);
        for(int i=2;i<nums.size();i++){
            ans[i] = max(ans[i-2]+nums[i], ans[i-1]);
        }
        for(int num:ans){
            cout<<num<<" ";
        }
        return ans[nums.size()-1];
    }
};