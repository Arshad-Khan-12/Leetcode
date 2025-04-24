class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int>st;
        for(int i:nums){
            st.insert(i);
        }
        int ans=0;
        int dis = st.size();
        for(int i=0;i<nums.size();i++){
            int cur=0;
            unordered_set<int>st2;
            for(int j=i;j<nums.size();j++){
                if(!st2.count(nums[j])){
                    cur++;
                }
                st2.insert(nums[j]);
                if(cur>=dis){
                    ans++;
                }
            }
        }
        return ans;
    }
};