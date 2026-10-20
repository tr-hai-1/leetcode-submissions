class Solution {
public:
    void backtracking(int step, int target, vector<int>& candidates, vector<int>& cur, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(cur);
            return;
        }
        for (int i = step; i < (int)candidates.size(); i++) {
            if (i > step && candidates[i] == candidates[i - 1]) {
                continue;
            }
            if (candidates[i] > target) {
                break;
            }
            cur.push_back(candidates[i]);
            backtracking(i + 1, target - candidates[i], candidates, cur, ans);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> cur;
        vector<vector<int>> ans;
        backtracking(0, target, candidates, cur, ans);
        return ans;
    }
};