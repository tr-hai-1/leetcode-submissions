class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        int n = strs.size();
        string sol = "";
        for (int i = 0; i < (int)min(strs[0].size(), strs[n - 1].size()); i++) {
            if (strs[0][i] != strs[n - 1][i])
                return sol;
            sol += strs[0][i];
        }
        return sol;
    }
};