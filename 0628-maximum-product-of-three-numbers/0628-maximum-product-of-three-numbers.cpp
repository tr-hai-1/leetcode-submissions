class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        priority_queue<int> pqMn;
        priority_queue<int, vector<int>, greater<int>> pqMx;
        for (int num : nums) {
            pqMn.push(num);
            pqMx.push(num);
            if (pqMn.size() > 2) pqMn.pop();
            if (pqMx.size() > 3) pqMx.pop();
        }
        int res1 = 1;
        int res2 = 1;
        while (!pqMx.empty()) {
            int x = pqMx.top();
            res1 *= x;
            if (pqMx.size() == 1) res2 *= x;
            pqMx.pop();
        }
        while (!pqMn.empty()) {
            int x = pqMn.top();
            res2 *= x;
            pqMn.pop();
        }
        return max(res1, res2);
    }
};