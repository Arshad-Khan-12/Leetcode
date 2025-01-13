class Solution {
public:
    int minimumLength(string s) {
        int ans=s.size();
        unordered_map<char,int>mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
            if(mpp[s[i]] == 3){
                ans-=2;
                mpp[s[i]]=1;
            }
        }
        return ans;
    }
};