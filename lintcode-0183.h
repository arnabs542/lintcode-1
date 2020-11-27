#ifndef __LINTCODE_0183__
#define __LINTCODE_0183__

#include "Lintcode.h"


/*@183. Wood Cut.
Given n pieces of wood with length L[i] (integer array).
Cut them into small pieces to guarantee you could have equal or more than k pieces with the same length.
What is the longest length you can get from the n pieces of wood? Given L & k, return the maximum length of the small pieces.

Example 1
    Input: L = [232, 124, 456] k = 7
    Output: 114
    Explanation: We can cut it into 7 pieces if any piece is 114cm long, however we can't cut it into 7 pieces if any piece is 115cm long.

Example 2
    Input: L = [1, 2, 3] k = 7
    Output: 0
    Explanation: It is obvious we can't make it.

Challenge
    O(n log Len), where Len is the longest length of the wood.

Notice
    You couldn't cut wood into float length.
    If you couldn't get >= k pieces, return 0.
*/
class Solution183
{
public:
    int woodCut(std::vector<int>& L, int k)
    {
        // write your code here
        if (L.empty()) {
            return 0;
        }

        int start = 0;
        int end = *(max_element(L.begin(), L.end()));

        while (start + 1 < end) {

            int mid = start + (end - start) / 2;

            if (countPieces(L, mid) >= k) {
                start = mid;
            }
            else {
                end = mid;
            }
        }

        if (end != 0 && countPieces(L, end) >= k) {
            return end;
        }

        if (start != 0 && countPieces(L, start) >= k) {
            return start;
        }

        return 0;
    }

private:
    int countPieces(std::vector<int>& nums, int length)
    {
        int cnt = 0;
        for (auto item : nums) {
            cnt += item / length;
        }

        return cnt;
    }
};

#endif

