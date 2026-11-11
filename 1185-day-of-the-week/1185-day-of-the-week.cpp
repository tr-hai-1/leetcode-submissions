class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
      vector<string> res = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
      vector<int> dm = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
      int days = (year - 1971) * 365 + dm[month - 1] + day;
      if (month > 2) days += (year - 1968) / 4;
      else days += (year - 1969) / 4;
      if (year == 2100 && month > 2) days--;
      return res[(4 + days) % 7];
    }
};