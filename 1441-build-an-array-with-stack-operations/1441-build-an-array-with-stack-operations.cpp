class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
      vector<string> res;
      int i = 0, curr = 1; 
      while (i < (int)target.size()) {
        for (int j = curr; j < target[i]; j++) {
          res.push_back("Push");
          res.push_back("Pop");
        }
        res.push_back("Push");
        curr = target[i] + 1;
        i++;
      }
      return res;
    }
};