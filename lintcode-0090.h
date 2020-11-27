#ifndef __LINTCODE_0090__
#define __LINTCODE_0090__

#include "data-types.h"

/*@90. k Sum II
Given n unique postive integers, number k (1<=k<=n) and target.
Find all possible k integers where their sum is target.

Example 1:
    Input: [1,2,3,4], k = 2, target = 5
    Output:  [[1,4],[2,3]]

Example 2:
    Input: [1,3,4,6], k = 3, target = 8
    Output:  [[1,3,4]]
*/
class Solution90
{
public:
    std::vector<std::vector<int>> kSumII(std::vector<int>& A, int k, int target)
    {
        std::vector<std::vector<int>> results;

        if (A.empty()) {
            return results;
        }

        sort(A.begin(), A.end());

        std::vector<int> subset;
        dfs(A, 0, k, target, subset, results);

        return results;
    }

private:
    void dfs(std::vector<int>& A, int index, int k, int target, std::vector<int>& subset, std::vector<std::vector<int>>& results)
    {
        if (k == 0 && target == 0) {
            results.push_back(subset);
            return;
        }

        if (k == 0 || target <= 0) {
            return;
        }

        for (int i = index; i < (int)A.size(); i++) {
            subset.push_back(A[i]);
            dfs(A, i + 1, k - 1, target - A[i], subset, results);
            subset.pop_back();
        }
    }
};

#endif

