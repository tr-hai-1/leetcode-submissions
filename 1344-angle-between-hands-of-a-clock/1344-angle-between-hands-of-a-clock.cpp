class Solution {
public:
    double angleClock(int hour, int minutes) {
      hour %= 12;
      double minutesAngle = 1.0 * minutes / 60 * 360;
      double hourAngle = 1.0 * hour / 12 * 360 + 1.0 * minutes / 60 * 30;
      double res = abs(minutesAngle - hourAngle);
      if (res > 180) res = 360 - res;
      return res;
    }
};