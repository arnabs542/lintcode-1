#ifndef __LINTCODE_0016__
#define __LINTCODE_0016__

#include "data-types.h"

/*@16. Permutations II
Given a list of numbers with duplicate number in it. Find all unique permutations.

Example 1:
    Input: [1,1]
    Output:
        [
          [1,1]
        ]

Example 2:
    Input: [1,2,2]
    Output:
        [
          [1,2,2],
          [2,1,2],
          [2,2,1]
        ]

Challenge
    Using recursion to do it is acceptable. If you can do it without recursion, that would be great!
*/
class Solution16
{
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums)
    {
        std::vector<std::vector<int>> results;
        std::vector<bool> visited(nums.size(), false);

        sort(nums.begin(), nums.end());

        std::vector<int> subset;
        dfs(nums, visited, subset, results);

        return results;
    }

private:
    void dfs(std::vector<int>& nums, std::vector<bool>& visited, std::vector<int>& subset, std::vector<std::vector<int>>& results)
    {
        if (subset.size() == nums.size()) {
            results.push_back(subset);
            return;
        }

        for (int i = 0; i < (int)nums.size(); i++) {
            if (visited[i]) {
                continue;
            }

            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) {
                continue;
            }

            subset.push_back(nums[i]);
            visited[i] = true;
            dfs(nums, visited, subset, results);
            visited[i] = false;
            subset.pop_back();
        }
    }
};

#endif

