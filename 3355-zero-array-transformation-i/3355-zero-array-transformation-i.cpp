class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);
        for (const auto& v : queries) {
            int l = v[0], r = v[1];
            diff[l]--;
            diff[r + 1]++;
        }
        for (int i = 1; i <= n; i++) diff[i] += diff[i - 1];
        for (int i = 0; i < n; i++) {
            if (nums[i] > -diff[i]) return false;
        }
        return true;
    }
};