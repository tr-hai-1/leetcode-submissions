class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> firstRow = {1};
        ans.push_back(firstRow);
        for (int i = 1; i < numRows; i++){
            vector<int> row(i + 1);
            row[0] = 1;
            row[i] = 1;
            for (int j = 1; j < i; j++){
                row[j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
            ans.push_back(row);
        }
        return ans;
    }
};