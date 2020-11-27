#ifndef __LINTCODE_0018__
#define __LINTCODE_0018__

#include "data-types.h"

/*Medium@18. Subsets II
Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Example 1:
	Input: [0]
	Output:[[],[0]]

Example 2:
	Input: [1,2,2]
	Output:[[2],[1],[1,2,2],[2,2],[1,2],[]]

Challenge
	Can you do it in both recursively and iteratively?

Notice
	Each element in a subset must be in non-descending order.
	The ordering between two subsets is free.
	The solution set must not contain duplicate subsets.
*/
class Solution18_1
{
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums)
    {
        std::vector<int> subset;
        std::vector<std::vector<int>> results;

        sort(nums.begin(), nums.end());
        dfs(nums, 0, subset, results);

        return results;
    }

private:
    void dfs(std::vector<int> nums, int startIndex, std::vector<int>& subset, std::vector<std::vector<int>>& results)
    {
        std::vector<int> newSet(subset);
        results.emplace_back(newSet);

        for (int i = startIndex; i < (int)nums.size(); i++) {
            if (i > startIndex && nums[i] == nums[i - 1]) {
                continue;
            }

            subset.emplace_back(nums[i]);
            dfs(nums, i + 1, subset, results);
            subset.pop_back();
        }
    }
};

class Solution18_2
{
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums)
    {
        // write your code here
        std::vector<std::vector<int>> results;
        std::unordered_set<std::string> visited;

        sort(nums.begin(), nums.end());

        std::vector<int> subset;
        dfs(nums, 0, subset, results, visited);

        return results;
    }

private:
    std::string getHash(std::vector<int>& subset)
    {
        std::string hashString = "";
        for (auto e : subset) {
            hashString += std::to_string(e);
            hashString += "-";
        }
        return hashString;
    }


    void dfs(std::vector<int>& nums, int startIndex, std::vector<int>& subset, std::vector<std::vector<int>>& results, std::unordered_set<std::string>& visited) 
    {

        std::string hashString = getHash(subset);
        if (visited.count(hashString)) {
            return;
        }

        visited.insert(hashString);
        results.push_back(std::vector<int>(subset));

        for (int i = startIndex; i < (int)nums.size(); i++) {
            subset.push_back(nums[i]);
            dfs(nums, i + 1, subset, results, visited);
            subset.pop_back();
        }
    }
};

#endif

