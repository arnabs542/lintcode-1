#ifndef __LINTCODE_0548__
#define __LINTCODE_0548__

#include "data-types.h"

/*@548. Intersection of Two Arrays II
Given two arrays, write a function to compute their intersection.

Example1
    Input: nums1 = [1, 2, 2, 1], nums2 = [2, 2]
    Output: [2, 2]

Example2
    Input: nums1 = [1, 1, 2], nums2 = [1]
    Output: [1]

Challenge
    What if the given array is already sorted? How would you optimize your algorithm?
    What if nums1's size is small compared to num2's size? Which algorithm is better?
    What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?

Notice
    Each element in the result should appear as many times as it shows in both arrays.
    The result can be in any order.
*/
class Solution548 
{
public:
    /**
     * @param nums1: an integer array
     * @param nums2: an integer array
     * @return: an integer array
     */
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) 
    {
        if (nums1.empty() || nums2.empty()) {
            return {};
        }

        std::vector<int> result;

        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        int i = 0, j = 0;
        while (i < (int)nums1.size() && j < (int)nums2.size()) {
            if (nums1[i] < nums2[j]) {
                i++;
            }
            else if (nums1[i] > nums2[j]) {
                j++;
            }
            else {
                result.push_back(nums1[i]);
                i++;
                j++;
            }
        }

        return result;
    }
};

#endif

