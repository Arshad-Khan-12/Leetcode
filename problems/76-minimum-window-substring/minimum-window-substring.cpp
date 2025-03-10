class Solution {
public:
    string minWindow(string s, string t) {
        int hash[256] = {0};
        int cnt=0;
        int m=t.size();
        for(const auto &i : t){
            hash[i]++;
        }
        int minlen = INT_MAX;
        int ind=-1;
        int l=0;
        int r=0;
        while(r < s.size()){
            if(hash[s[r]] > 0){
                cnt++;
            }
                hash[s[r]]--;
            while(cnt == m){
                if(r-l + 1 < minlen){
                    minlen=r-l+1;
                    ind=l;
                }
                hash[s[l]]++;
                if(hash[s[l]] > 0){
                    cnt--;
                }
                l++;
            }
            r++;
        }
        return ind==-1 ? "" : s.substr(ind,minlen);
    }
};