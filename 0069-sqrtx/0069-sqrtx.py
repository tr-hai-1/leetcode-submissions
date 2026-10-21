class Solution:
    def mySqrt(self, x: int) -> int:
        if x < 2: 
            return x
        l, r = 1, x
        while l <= r:
            m = l + (r - l) // 2
            if m <= x // m:
                ans = m
                l = m + 1
            else:
                r = m - 1
        return ans