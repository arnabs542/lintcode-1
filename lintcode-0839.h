#ifndef __LINTCODE_0839__
#define __LINTCODE_0839__

#include "data-types.h"

/*@839. Merge Two Sorted Interval Lists
Merge two sorted (ascending) lists of interval and return it as a new sorted list.
The new sorted list should be made by splicing together the intervals of the two lists and sorted in ascending order.

Example1
    Input: list1 = [(1,2),(3,4)] and list2 = [(2,3),(5,6)]
    Output: [(1,4),(5,6)]
    Explanation:
        (1,2),(2,3),(3,4) --> (1,4)
        (5,6) --> (5,6)

Example2
    Input: list1 = [(1,2),(3,4)] and list2 = [(4,5),(6,7)]
    Output: [(1,2),(3,5),(6,7)]
    Explanation:
        (1,2) --> (1,2)
        (3,4),(4,5) --> (3,5)
        (6,7) --> (6,7)
Notice
    The intervals in the given list do not overlap.
    The intervals in different lists may overlap.
*/
class Solution839 
{
public:
    /**
     * @param list1: one of the given list
     * @param list2: another list
     * @return: the new sorted list of interval
     */
    std::vector<Interval> mergeTwoInterval(std::vector<Interval>& list1, std::vector<Interval>& list2) 
    {
        if (list1.empty() || list2.empty()) {
            return list1.empty() == true ? list2 : list1;
        }

        std::vector<Interval> intervals;

        int idx1 = 0, idx2 = 0;
        while (idx1 < (int)list1.size() && idx2 < (int)list2.size()) {
            if (list1[idx1].start < list2[idx2].start) {
                pushBack(intervals, list1[idx1]);
                idx1++;
            }
            else {
                pushBack(intervals, list2[idx2]);
                idx2++;
            }
        }
        while (idx1 < (int)list1.size()) {
            pushBack(intervals, list1[idx1]);
            idx1++;
        }
        while (idx2 < (int)list2.size()) {
            pushBack(intervals, list2[idx2]);
            idx2++;
        }

        return intervals;
    }

private:
    void pushBack(std::vector<Interval>& intervals, Interval a) 
    {
        if (intervals.empty()) {
            intervals.push_back(a);
            return;
        }

        Interval last = intervals.back();
        if (last.end < a.start) {
            intervals.push_back(a);
            return;
        }

        intervals.back().end = std::max(last.end, a.end);
    }
};

#endif

