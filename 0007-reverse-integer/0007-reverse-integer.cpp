class Solution {
public:
    int reverse(int x) {
        bool neg;
        long long y = x;
        if (y < 0) {
            neg = true;
            y = -y;
        } else {
            neg = false;
        }
        long long tempX = y;
        string s;
        while (tempX > 0) {
            char digit = (tempX % 10) + '0';
            s += digit;
            tempX /= 10;
        }
        long long base = 1;
        long long ans = 0;
        for (int i = (int)s.size() - 1; i >= 0; i--) {
            ans += (s[i] - '0') * base;
            base *= 10;
        }
        if (neg)
            ans = -ans;
        if (ans >= (1LL << 31) || ans < -(1LL << 31))
            return 0;
        else
            return (int)ans;
    }
};