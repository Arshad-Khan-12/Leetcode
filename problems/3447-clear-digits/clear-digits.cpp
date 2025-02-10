class Solution {
public:
    string clearDigits(string s) {
        unordered_map<int, int> mpp;
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                mpp[i]++;
                int j = i-1;
                while (j >= 0) {
                    if (isalpha(s[j]) && mpp.find(j) == mpp.end()) {
                        mpp[j]++;
                        break;
                    }
                    j--;
                }
            }
        }

        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            if (mpp.find(i) == mpp.end()) {
                ans += s[i];
            }
        }
        return ans;
    }
};