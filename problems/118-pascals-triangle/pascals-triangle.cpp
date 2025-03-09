class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>ans;
        ans.push_back({1});
        for(int i=2;i<=n;i++){
            vector<int>a;
            vector<int>b = ans.back();
            int l=0;
            int r=1;
            a.push_back(1);
            for(int j=1;j<i-1;j++){
                int el = b[l] + b[r];
                a.push_back(el);
                l++;
                r++;
            }
            a.push_back(1);
            ans.push_back(a);
        }
        return ans;
    }
};