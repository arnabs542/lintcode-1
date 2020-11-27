#ifndef __LINTCODE_0015__
#define __LINTCODE_0015__

#include "data-types.h"

/*@15. Permutations
Given a list of numbers, return all possible permutations.
Example 1:
    Input: [1]
    Output:[[1]]

Example 2:
    Input: [1,2,3]
    Output:[
              [1,2,3],
              [1,3,2],
              [2,1,3],
              [2,3,1],
              [3,1,2],
              [3,2,1]
            ]
Challenge
    Do it without recursion.

Notice
    You can assume that there is no duplicate numbers in the list.
*/
class Solution15
{
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums)
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

            subset.push_back(nums[i]);
            visited[i] = true;
            dfs(nums, visited, subset, results);
            visited[i] = false;
            subset.pop_back();
        }
    }
};

#endif

