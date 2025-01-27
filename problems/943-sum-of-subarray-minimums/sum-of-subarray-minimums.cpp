class Solution {
public:
    vector<int> findNse(vector<int> &arr){
        int n=arr.size();
        vector<int>nse(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            nse[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> findPsee(vector<int> &arr){
        int n=arr.size();
        vector<int>psee(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            psee[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return psee;
    }
    int sumSubarrayMins(vector<int>& arr) {
        vector<int>nse = findNse(arr);
        vector<int>psee = findPsee(arr);
        int mod = (int)(1e9 + 7);
        int sum=0;
        for(int i=0;i<arr.size();i++){
            int left = i - nse[i];
            int right = psee[i] - i;
            sum =(sum + (left*right*1LL*arr[i])%mod)%mod;
        }
        return sum;
    }
};