/* Given a date, return the corresponding day of the week for that date.
 * The input is given as three integers representing the day, month and
 * year respectively.
 *
 * Return the answer as one of the following values {"Sunday", "Monday",
 * "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}.
 *
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions.
 * Memory usage: 7.3 MB, less than 100.00% of C++ online submissions.
 */

#include <iostream>

std::string dayOfTheWeek(int day, int month, int year) {
  bool leap = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
  
  int dayInYear = 0;
  for (int i = 1; i < month; ++i) {
    if (i <= 7) {
      if (i % 2 != 0) dayInYear += 31;
      else            dayInYear += 30;
    } else {
      if (i % 2 == 0) dayInYear += 31;
      else            dayInYear += 30;
    }
  }
  if (month > 2) {
    if (leap) dayInYear -= 1;
    else      dayInYear -= 2;
  }
  dayInYear += day;
  
  // 1971 january 1 was friday
  // 1 2 3 4 5 6 7
  // 0 1 2 3 4 5 6
  int weekday = 4 + dayInYear - 1;
    
  weekday += 365 * (year - 1971);
  
  int leapYears = 0;
  for (int y = 1971; y < year; ++y) {
      if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0)) ++leapYears;
  }
  weekday += leapYears;  
  
  weekday = weekday % 7;
    
  std::string res;
  switch (weekday) {
    case 0: res = "Monday"; break;
    case 1: res = "Tuesday"; break;
    case 2: res = "Wednesday"; break;
    case 3: res = "Thursday"; break;
    case 4: res = "Friday"; break;
    case 5: res = "Saturday"; break;
    case 6: res = "Sunday"; break;
  }
  return res;
}

int main() {
  std::cout << dayOfTheWeek(31, 8, 2019) << '\n';
}
