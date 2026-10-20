class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 1) return intervals;
        sort(intervals.begin(), intervals.end());
        vector<int> curr = intervals[0];
        vector<vector<int>> res;
        for (int i = 1; i < n; i++) {
            if (curr[1] >= intervals[i][0]) {
                curr[1] = max(curr[1], intervals[i][1]);
            } else {
                res.push_back(curr);
                curr = intervals[i];
            }
            if (i == n - 1) res.push_back(curr);
        }
        return res;
    }
};