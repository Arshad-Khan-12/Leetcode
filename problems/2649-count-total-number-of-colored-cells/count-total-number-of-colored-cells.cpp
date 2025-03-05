class Solution {
public:
    long long coloredCells(int n) {
        long long ans=1;
        long long l=4;
        for(int i=2;i<=n;i++){
            ans += l;
            l+=4;
        }
        return ans;
    }
};