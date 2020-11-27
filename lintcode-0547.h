#ifndef __LINTCODE_0547__
#define __LINTCODE_0547__

#include "data-types.h"


/*@547. Intersection of Two Arrays
Given two arrays, write a function to compute their intersection.

Example
Example 1:
    Input: nums1 = [1, 2, 2, 1], nums2 = [2, 2],
    Output: [2].

Example 2:
    Input: nums1 = [1, 2], nums2 = [2],
    Output: [2].

Challenge
    Can you implement it in three different algorithms?

Notice
    Each element in the result must be unique.
    The order of the results needs to be ascending
*/
class Solution547 
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

        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        std::vector<int> result;

        int i = 0, j = 0;
        while (i < (int)nums1.size() && j < (int)nums2.size()) {
            if (nums1[i] == nums2[j]) {
                result.push_back(nums1[i]);
                i++;
                j++;
            }
            else if (nums1[i] < nums2[j]) {
                i++;
            }
            else {
                j++;
            }
        }

        auto pos = std::unique(result.begin(), result.end());
        result.erase(pos, result.end());

        return result;
    }
};

class Solution547HashMap 
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

        std::unordered_set<int> hashset;
        for (int i = 0; i < (int)nums1.size(); i++) {
            hashset.insert(nums1[i]);
        }

        std::vector<int> result;
        for (int i = 0; i < (int)nums2.size(); i++) {
            if (hashset.count(nums2[i])) {
                result.push_back(nums2[i]);
                hashset.erase(nums2[i]);
            }
        }

        return result;
    }
};

class Solution547HashMap_1 
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

        std::unordered_set<int> hashset(nums1.begin(), nums1.end());

        std::unordered_set<int> result;
        for (int i = 0; i < (int)nums2.size(); i++) {
            if (hashset.count(nums2[i])) {
                result.insert(nums2[i]);
            }
        }

        return std::vector<int>(result.begin(), result.end());
    }
};

class Solution547TwoSortedArray 
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

        std::unordered_set<int> result;

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
                result.insert(nums1[i]);
                i++;
                j++;
            }
        }

        return std::vector<int>(result.begin(), result.end());
    }
};

#endif
