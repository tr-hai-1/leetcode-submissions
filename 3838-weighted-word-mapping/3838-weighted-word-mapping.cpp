class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
      string res;
      int sum;
      for (auto &s : words) {
        sum = 0;
        for (char ch : s) {
          sum += weights[ch - 'a'];
        }
        sum %= 26;
        res += 'z' - sum;
      }
      return res;
    }
};