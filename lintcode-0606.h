#ifndef __LINTCODE_0606__
#define __LINTCODE_0606__

#include "data-types.h"


/*@606. Kth Largest Element II
Find K-th largest element in an array. and N is much larger than k.
Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:
    Input:[9,3,2,4,8],3
    Output:4

Example 2:
    Input:[1,2,3,4,5,6,8,9,10,7],10
    Output:1

Notice
    You can swap elements in the array
*/
class Solution606 
{
public:
    /**
     * @param nums: an integer unsorted array
     * @param k: an integer from 1 to n
     * @return: the kth largest element
     */
    int kthLargestElement2(std::vector<int>& nums, int k) 
    {
        if (nums.empty() || (int)nums.size() < k) {
            return -1;
        }

        std::sort(nums.begin(), nums.end(), std::greater<int>());

        return nums[k - 1];

    }
};

class Solution606QuickSelect 
{
public:
    /**
     * @param nums: an integer unsorted array
     * @param k: an integer from 1 to n
     * @return: the kth largest element
     */
    int kthLargestElement2(std::vector<int>& nums, int k) {
        if (nums.empty() || (int)nums.size() < k) {
            return -1;
        }

        return quickSelect(nums, 0, nums.size() - 1, k);
    }

private:
    int quickSelect(std::vector<int>& nums, int start, int end, int k) 
    {
        if (start == end) {
            return nums[start];
        }

        int left = start, right = end;
        int pivot = nums[start + (right - start) / 2];
        while (left <= right) {
            while (left <= right && nums[left] > pivot) {
                left++;
            }
            while (left <= right && nums[right] < pivot) {
                right--;
            }
            if (left <= right) {
                std::swap(nums[left], nums[right]);
                left++;
                right--;
            }
        }

        if (start + k - 1 <= right) {
            return quickSelect(nums, start, right, k);
        }

        if (start + k - 1 >= left) {
            return quickSelect(nums, left, end, k - (left - start));
        }

        return nums[right + 1];
    }
};

class Solution606Heap 
{
public:
    /**
     * @param nums: an integer unsorted array
     * @param k: an integer from 1 to n
     * @return: the kth largest element
     */
    int kthLargestElement2(std::vector<int>& nums, int k) 
    {
        if (nums.empty() || (int)nums.size() < k) {
            return -1;
        }

        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        for (int i = 0; i < (int)nums.size(); i++) {
            pq.push(nums[i]);
            if ((int)pq.size() > k) {
                pq.pop();
            }
        }

        return pq.top();
    }
};

#endif

