class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n + 1);
        for (const auto &v : shifts) {
            int l = v[0], r = v[1], d = v[2];
            if (d) {
                diff[l]++;
                diff[r + 1]--;
            } else {
                diff[l]--;
                diff[r + 1]++;
            }
        }
        for (int i = 1; i <= n; i++) diff[i] += diff[i - 1];
        string res;
        for (int i = 0; i < n; i++) {
            int shift = (diff[i] % 26 + 26) % 26;
            res += 'a' + (s[i] - 'a' + shift) % 26;
        }
        return res;
    }
};