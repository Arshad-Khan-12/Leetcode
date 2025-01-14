class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int>ans(n,0);
        unordered_map<int,int>mppA;
        unordered_map<int,int>mppB;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(A[i] == B[i]){
                mppA[A[i]]++;
                mppB[B[i]]++;
                cnt++;
                ans[i]=cnt;
            }
            else{
                if(mppB[A[i]] > 0){
                    cnt++;
                }
                if(mppA[B[i]] > 0){
                    cnt++;
                }
                mppA[A[i]]++;
                mppB[B[i]]++;
                ans[i]=cnt;
            }
        }
        return ans;

    }
};