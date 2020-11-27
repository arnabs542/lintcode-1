#ifndef __LINTCODE_0143__
#define __LINTCODE_0143__

#include "data-types.h"


/*@143. Sort Colors II
Given an array of n objects with k different colors (numbered from 1 to k), sort them so that objects of the same color are adjacent, with the colors in the order 1, 2, ... k.

Example1
    Input:
        [3,2,2,1,4]
        4
    Output:
        [1,2,2,3,4]

Example2
    Input:
        [2,1,1,2,2]
        2
    Output:
        [1,1,2,2,2]
Challenge
    A rather straight forward solution is a two-pass algorithm using counting sort. That will cost O(k) extra memory. Can you do it without using extra memory?

Notice
    You are not suppose to use the library's sort function for this problem.
    k <= n
*/
class Solution143 
{
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */
    void sortColors2(std::vector<int>& colors, int k) {
        if (colors.empty() || k <= 0) {
            return;
        }

        rainbowSort(colors, 0, colors.size() - 1, 1, k);
    }

    void rainbowSort(std::vector<int>& colors, int left, int right, int colorFrom, int colorTo) {
        if (colorFrom == colorTo) {
            return;
        }

        if (left >= right) {
            return;
        }

        int colorMid = (colorFrom + colorTo) / 2;
        int l = left, r = right;
        while (l <= r) {
            while (l <= r && colors[l] <= colorMid) {
                l++;
            }
            while (l <= r && colors[r] > colorMid) {
                r--;
            }

            if (l <= r) {
                std::swap(colors[l], colors[r]);
                l++;
                r--;
            }
        }

        rainbowSort(colors, left, r, colorFrom, colorMid);
        rainbowSort(colors, l, right, colorMid + 1, colorTo);
    }
};

#endif
