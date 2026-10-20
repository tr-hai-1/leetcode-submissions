class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || (int)t.size() > (int)s.size())
            return "";
        unordered_map<char, int> cnt, window;
        for (char ch : t)
            cnt[ch]++;
        int have = 0, need = cnt.size();
        int l = 0;
        int resSize = INT_MAX;
        pair<int, int> pos = {-1, -1};
        for (int r = 0; r < (int)s.size(); r++) {
            char ch = s[r];
            window[ch]++;
            if (cnt.count(ch) && cnt[ch] == window[ch])
                have++;
            while (have == need) {
                if (r - l + 1 < resSize) {
                    resSize = r - l + 1;
                    pos = {l, r};
                }
                window[s[l]]--;
                if (cnt.count(s[l]) && window[s[l]] < cnt[s[l]])
                    have--;
                l++;
            }
        }
        if (resSize == INT_MAX)
            return "";
        string res;
        for (int i = pos.first; i <= pos.second; i++)
            res += s[i];
        return res;
    }
};