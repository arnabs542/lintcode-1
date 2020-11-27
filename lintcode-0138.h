#ifndef __LINTCODE_0138__
#define __LINTCODE_0138__

#include "data-types.h"

/*138. Subarray Sum
Given an integer array, find a subarray where the sum of numbers is zero.
Your code should return the index of the first number and the index of the last number.

Example
	Input:  [-3, 1, 2, -3, 4]
	Output: [0, 2] or [1, 3].
	Explanation: return anyone that the sum is 0.

Example 2:
	Input:  [-3, 1, -4, 2, -3, 4]
	Output: [1,5]

Notice
There is at least one subarray that it's sum equals to zero.
*/
class Solution138 
{
public:
	/**
	 * @param nums: A list of integers
	 * @return: A list of integers includes the index of the first number and the index of the last number
	 */
	std::vector<int> subarraySum(std::vector<int>& nums) 
	{
		// write your code here
		if (nums.empty()) {
			return {};
		}

		std::vector<int> result;
		std::unordered_map<int, int> hash;
		int sum = 0;
		hash[0] = -1;

		for (int i = 0; i < (int)nums.size(); i++) {
			sum += nums[i];

			if (hash.count(sum)) {
				result.push_back(hash[sum] + 1);
				result.push_back(i);
				break;
			}

			hash[sum] = i;
		}

		return result;
	}
};

#endif

