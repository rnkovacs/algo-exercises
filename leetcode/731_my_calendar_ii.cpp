/* Implement a MyCalendarTwo class to store your events. A new event can be
 * added if adding the event will not cause a triple booking. A triple booking
 * happens when three events have some non-empty intersection (ie., there is
 * some time that is common to all 3 events.)
 *
 * For each call to the method MyCalendar.book, return true if the event can
 * be added to the calendar successfully without causing a triple booking.
 * Otherwise, return false and do not add the event to the calendar.
 *
 * Runtime: 664 ms, faster than 5.02% of C++ online submissions.
 * Memory usage: 34.5 MB, lesss than 66.67% of C++ online submissions.
 */

class MyCalendarTwo {
  std::multiset<int> starts;
  std::multiset<int> ends;
    
public:
  bool book(int start, int end) {
    starts.insert(start);
    ends.insert(end);
    
    int sameTime = 0;
    auto si = starts.begin();
    auto ei = ends.begin();
    
    while (si != starts.end() && ei != ends.end()) {
      if (*si == *ei) {
        ++si;
        ++ei;
      }
      else if (*si < *ei) {
        ++sameTime;
        if (sameTime == 3) {
            starts.erase(starts.lower_bound(start));
            ends.erase(ends.lower_bound(end));
            return false;
        }
        ++si;
      }
      else {
        ++ei;
        --sameTime;
      }
    }
    
    return true;
  }
};
