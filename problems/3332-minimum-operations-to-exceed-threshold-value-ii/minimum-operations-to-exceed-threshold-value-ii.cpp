class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long, vector<long>, greater<long>> pq;
        for(int i:nums){
            pq.push(i);
        }
        int ans=0;
        while(pq.top() < k){
            long x = pq.top();
            pq.pop();
            long y = pq.top();
            pq.pop();
            long val = min(x,y) * 2 + max(x,y);
            pq.push(val);
            ans++;
        }
        return ans;

    }
};