class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        int n1 = num1.size() - 1;
        int n2 = num2.size() - 1;
        vector<int> ans(n1 + n2 + 2, 0);
        for (int i = n1; i >= 0; i--) {
            for (int j = n2; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + ans[i + j + 1];
                ans[i + j + 1] = sum % 10;
                ans[i + j] += sum / 10;
            }
        }
        string res;
        for (int x : ans) {
            if (!(res.empty() && x == 0))
                res += (x + '0');
        }
        return res;
    }
};