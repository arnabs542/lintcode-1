#ifndef __LINTCODE_0017__
#define __LINTCODE_0017__

#include "data-types.h"

/*@17. Subsets
Given a set of distinct integers, return all possible subsets.

Example
Example 1:

Input: [0]
Output:
[
  [],
  [0]
]
Example 2:

Input: [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
Challenge
Can you do it in both recursively and iteratively?

Notice
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
*/
class Solution17 
{
public:
    /**
     * @param nums: A set of numbers
     * @return: A list of lists
     */
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) 
    {
        // write your code here
        std::vector<std::vector<int>> queue;
        queue.push_back(std::vector<int>());

        sort(nums.begin(), nums.end());

        for (int num : nums) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                std::vector<int> subset = queue[i];
                subset.push_back(num);
                queue.push_back(subset);
            }
        }

        return queue;
    }
};

class Solution17_2
{
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums)
    {
        std::vector<std::vector<int>> results;
        std::vector<int> subset;

        sort(nums.begin(), nums.end());
        dfs(nums, 0, subset, results);
        return results;
    }

private:
    void dfs(std::vector<int>& nums, int index, std::vector<int>& subset, std::vector<std::vector<int>>& results)
    {
        if (index == nums.size()) {
            results.emplace_back(subset);
            return;
        }

        subset.emplace_back(nums[index]);
        dfs(nums, index + 1, subset, results);
        subset.pop_back();

        dfs(nums, index + 1, subset, results);
    }
};

class Solution17_3
{
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums)
    {
        std::vector<std::vector<int>> results;
        std::vector<int> subset;

        sort(nums.begin(), nums.end());
        dfs(nums, 0, subset, results);
        return results;
    }

private:
    void dfs(std::vector<int>& nums, int startIndex, std::vector<int>& subset, std::vector<std::vector<int>>& results)
    {
        results.push_back(std::vector<int>(subset));

        for (int i = startIndex; i < (int)nums.size(); i++) {
            subset.push_back(nums[i]);
            dfs(nums, i + 1, subset, results);
            subset.pop_back();
        }
    }
};

class Solution17_4
{
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums)
    {
        std::vector<std::vector<int>> results;
        std::vector<int> subset;

        sort(nums.begin(), nums.end());
        dfs(nums, 0, subset, results);
        return results;
    }

private:
    void dfs(std::vector<int>& nums, int startIndex, std::vector<int>& subset, std::vector<std::vector<int>>& results)
    {
        results.emplace_back(subset);

        for (int i = startIndex; i < (int)nums.size(); i++) {

            std::vector<int> newSet(subset);
            newSet.emplace_back(nums[i]);
            dfs(nums, i + 1, newSet, results);
        }
    }
};

#endif

