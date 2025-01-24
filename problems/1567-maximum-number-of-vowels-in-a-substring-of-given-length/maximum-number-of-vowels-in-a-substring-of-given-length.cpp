class Solution {
public:
    int maxVowels(string s, int k) {
        int i = 0;
        int j = 0;
        int cnt = 0;
        int ans = 0;
        while (j < s.size()) {
            if (j >= k) {
                if (s[i] == 'a' || s[i] == 'e' || s[i] == 'o' || s[i] == 'i' ||
                    s[i] == 'u') {
                    cnt--;
                }
                i++;
            }
            if (s[j] == 'a' || s[j] == 'e' || s[j] == 'o' || s[j] == 'i' ||
                s[j] == 'u') {
                cnt++;
            }

            j++;
            ans = max(ans, cnt);
        }
        return ans;
    }
};