class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        int mx = 0;
        for (const auto& v : nums) {
            mx = max(mx, v[1]);
        }
        vector<int> diff(mx + 2, 0);
        for (const auto &v : nums) {
            int x = v[0], y = v[1];
            diff[x]++;
            diff[y + 1]--;
        }
        int res = mx;
        for (int i = 1; i <= mx; i++) {
            diff[i] += diff[i - 1];
            res -= (diff[i] == 0);
        }
        return res;
    }
};