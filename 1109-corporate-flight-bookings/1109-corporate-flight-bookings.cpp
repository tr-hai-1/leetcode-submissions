class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n + 1, 0);
        for (auto vec : bookings) {
            int l = vec[0] - 1, r = vec[1] - 1, s = vec[2];
            diff[l] += s;
            diff[r + 1] -= s;
        }
        vector<int> res(n, 0);
        res[0] = diff[0];
        for (int i = 1; i < n; i++) {
            res[i] = res[i - 1] + diff[i];
        }
        return res;
    }
};