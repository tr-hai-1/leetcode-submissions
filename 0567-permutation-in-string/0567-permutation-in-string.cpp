class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if ((int)s1.size() > (int)s2.size())
            return false;
        vector<int> cnt(26, 0);
        vector<int> check(26, 0);
        int matches = 0;
        for (int i = 0; i < (int)s1.size(); i++) {
            cnt[s1[i] - 'a']++;
            check[s2[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (cnt[i] == check[i])
                matches++;
        }
        if (matches == 26)
            return true;
        int l = 0;
        for (int r = (int)s1.size(); r < (int)s2.size(); r++) {
            check[s2[r] - 'a']++;
            if (cnt[s2[r] - 'a'] == check[s2[r] - 'a'])
                matches++;
            else if (cnt[s2[r] - 'a'] + 1 == check[s2[r] - 'a'])
                matches--;
            check[s2[l] - 'a']--;
            if (cnt[s2[l] - 'a'] == check[s2[l] - 'a'])
                matches++;
            else if (cnt[s2[l] - 'a'] - 1 == check[s2[l] - 'a'])
                matches--;
            l++;
            if (matches == 26)
                return true;
        }
        return false;
    }
};