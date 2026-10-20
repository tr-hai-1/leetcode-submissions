class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int mx = 0;
        for (const auto &v : trips) mx = max(mx, v[2]);
        vector<int> diff(mx + 2, 0);
        for (const auto &v : trips) {
            int x = v[0], l = v[1], r = v[2];
            diff[l] += x;
            diff[r] -= x;
        }
        if (diff[0] > capacity) return false;
        for (int i = 1; i <= mx; i++) {
            diff[i] += diff[i - 1];
            if (diff[i] > capacity) return false;
        }
        return true;
    }
};