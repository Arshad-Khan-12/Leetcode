class Solution {
    int sum=0;
public:
    void backtrack(int i, int n, int xorr, vector<int>& nums){
        if(i >= n){
            sum += xorr;
            return;
        }
        backtrack(i+1,n,xorr^nums[i],nums);
        backtrack(i+1,n,xorr,nums);

    }
    int subsetXORSum(vector<int>& nums) {
        
        backtrack(0,nums.size(),0,nums);
        return sum;
    }
};