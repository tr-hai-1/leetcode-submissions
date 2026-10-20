class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int resLen = 1;
        pair<int, int> resPos = {0, 0};
        for (int i = 0; i < n; i++) {
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > resLen) {
                    resPos = {l, r};
                    resLen = r - l + 1;
                }
                l--;
                r++;
            }
        }
        for (int i = 0; i < n - 1; i++) {
            int l = i, r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > resLen) {
                    resPos = {l, r};
                    resLen = r - l + 1;
                }
                l--;
                r++;
            }
        }
        string res;
        for (int i = resPos.first; i <= resPos.second; i++)
            res += s[i];
        return res;
    }
};