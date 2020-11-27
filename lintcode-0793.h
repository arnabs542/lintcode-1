#ifndef __LINTCODE_0587__
#define __LINTCODE_0587__

#include "data-types.h"

/*@793. Intersection of Arrays
Give a number of arrays, find their intersection, and output their intersection size.

Example 1:
    Input:  [[1,2,3],[3,4,5],[3,9,10]]
    Output:  1
    Explanation: Only '3' in all three array.

Example 2:
    Input: [[1,2,3,4],[1,2,5,6,7][9,10,1,5,2,3]]
    Output:  2
    Explanation: The set is [1,2].

Notice
    The total number of all array elements is not more than 500000.
    There are no duplicated elements in each array.
*/
class Solution793KSortedArrays 
{
public:
    /**
     * @param arrs: the arrays
     * @return: the number of the intersection of the arrays
     */
    int intersectionOfArrays(std::vector<std::vector<int>>& arrs) 
    {
        if (arrs.empty()) {
            return 0;
        }

        for (auto& arr : arrs) {   // MUST BE ADD '&'!!!!!
            std::sort(arr.begin(), arr.end());
        }

        while (arrs.size() > 1) {
            std::vector<std::vector<int>> newArrs;
            for (int i = 0; i + 1 < arrs.size(); i += 2) {
                std::vector<int> arr = findIntersections(arrs[i], arrs[i + 1]);
                newArrs.push_back(arr);
            }
            if (arrs.size() % 2) {
                newArrs.push_back(arrs.back());
            }

            arrs = newArrs;
        }

        return arrs[0].size();
    }

private:
    std::vector<int> findIntersections(std::vector<int>& a, std::vector<int>& b) 
    {
        if (a.empty() || b.empty()) {
            return {};
        }

        std::vector<int> result;
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] < b[j]) {
                i++;
            }
            else if (a[i] > b[j]) {
                j++;
            }
            else {
                result.push_back(a[i]);
                i++;
                j++;
            }
        }

        return result;
    }
};

class Solution739HashMap 
{
public:
    /**
     * @param arrs: the arrays
     * @return: the number of the intersection of the arrays
     */
    int intersectionOfArrays(std::vector<std::vector<int>>& arrs) 
    {
        if (arrs.empty()) {
            return 0;
        }

        std::unordered_map<int, int> hashmap;

        for (auto arr : arrs) {
            for (auto element : arr) {
                hashmap[element]++;
            }
        }

        int cnt = 0;
        for (int i = 0; i < hashmap.size(); i++) {
            if (hashmap[i] == arrs.size()) {
                cnt++;
            }
        }

        return cnt;
    }
};

#endif
