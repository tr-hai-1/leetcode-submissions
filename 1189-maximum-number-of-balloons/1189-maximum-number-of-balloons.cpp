class Solution {
public:
    int maxNumberOfBalloons(string text) {
      int cnt[26] = {};
      for (char ch : text) cnt[ch - 'a']++;
      int cnt1 = cnt['b' - 'a'];
      int cnt2 = cnt['a' - 'a'];
      int cnt3 = cnt['l' - 'a'] / 2;
      int cnt4 = cnt['o' - 'a'] / 2;
      int cnt5 = cnt['n' - 'a'];
      return min(min(min(min(cnt1, cnt2), cnt3) , cnt4), cnt5);
    }
};