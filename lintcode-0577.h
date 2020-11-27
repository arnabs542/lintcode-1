#ifndef __LINTCODE_0577__
#define __LINTCODE_0577__

#include "data-types.h"

/*@577. Merge K Sorted Interval Lists
Merge K sorted interval lists into one sorted interval list.
You need to merge overlapping intervals too.

Example1
    Input: [
              [(1,3),(4,7),(6,8)],
              [(1,2),(9,10)]
           ]
    Output: [(1,3),(4,8),(9,10)]

Example2
    Input: [
              [(1,2),(5,6)],
              [(3,4),(7,8)]
           ]
    Output: [(1,2),(3,4),(5,6),(7,8)]
*/
class Solution577 
{
public:
    /**
     * @param intervals: the given k sorted interval lists
     * @return:  the new sorted interval list
     */
    std::vector<Interval> mergeKSortedIntervalLists(std::vector<std::vector<Interval>>& intervals) 
    {
        if (intervals.empty()) {
            return {};
        }

        std::vector<Interval> arrays;
        for (int i = 0; i < (int)intervals.size(); i++) {
            for (int j = 0; j < (int)intervals[i].size(); j++) {
                arrays.push_back(intervals[i][j]);
            }
        }

        std::sort(arrays.begin(), arrays.end(), cmp);

        std::vector<Interval> result;
        result.push_back(arrays[0]);
        for (int i = 1; i < (int)arrays.size(); i++) {
            if (result.back().end < arrays[i].start) {
                result.push_back(arrays[i]);
            }
            else {
                result.back().end = std::max(result.back().end, arrays[i].end);
            }
        }

        return result;
    }

private:
    static bool cmp(Interval a, Interval b) 
    {
        //if (a.start == b.start) {
        //    return a.end < b.end;
        //}

        return a.start < b.start;
    }
};

#endif

