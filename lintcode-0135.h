#ifndef __LINTCODE_0135__
#define __LINTCODE_0135__

#include "data-types.h"

/*@135. Combination Sum
Given a set of candidtate numbers candidates and a target number target.
Find all unique combinations in candidates where the numbers sums to target.
The same repeated number may be chosen from candidates unlimited number of times.

Example 1:
    Input: candidates = [2, 3, 6, 7], target = 7
    Output: [[7], [2, 2, 3]]

Example 2:
    Input: candidates = [1], target = 3
    Output: [[1, 1, 1]]
Notice
    All numbers (including target) will be positive integers.
    Numbers in a combination a1, a2, … , ak must be in non-descending order. (ie, a1 <= a2 <= … <= ak)
    Different combinations can be in any order.
    The solution set must not contain duplicate combinations.
*/
class Solution135
{
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target)
    {
        // write your code here
        std::vector<std::vector<int>> results;
        sort(candidates.begin(), candidates.end());

        auto pos = std::unique(candidates.begin(), candidates.end());
        candidates.erase(pos, candidates.end());

        std::vector<int> subset;
        dfs(candidates, target, 0, subset, results);

        return results;
    }

    void dfs(std::vector<int>& nums, int target, int startIndex, std::vector<int>& subset, std::vector<std::vector<int>>& results)
    {

        if (target < 0) {
            return;
        }
        if (target == 0) {
            results.push_back(subset);
            return;
        }

        for (int i = startIndex; i < (int)nums.size(); i++) {
            subset.push_back(nums[i]);
            dfs(nums, target - nums[i], i, subset, results);
            subset.pop_back();
        }
    }
};

#endif

