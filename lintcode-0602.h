#ifndef __LINTCODE_0602__
#define __LINTCODE_0602__

#include "data-types.h"

/*@602. Russian Doll Envelopes
Give a number of envelopes with widths and heights given as a pair of integers (w, h). 
One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.
Find the maximum number of nested layers of envelopes.

Example 1:
    Input:[[5,4],[6,4],[6,7],[2,3]]
    Output:3
    Explanation:the maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).

Example 2:
    Input:[[4,5],[4,6],[6,7],[2,3],[1,1]]
    Output:4
    Explanation: the maximum number of envelopes you can Russian doll is 4 ([1,1] => [2,3] => [4,5] / [4,6] => [6,7]).
*/
class Solution602 
{
public:
    /**
     * @param envelopes: a number of envelopes with widths and heights
     * @return: the maximum number of envelopes
     */
    int maxEnvelopes(std::vector<std::vector<int>>& envelopes) {
        if (envelopes.empty() || envelopes[0].empty()) {
            return 0;
        }

        int n = envelopes.size();

        sort(envelopes.begin(), envelopes.end(), cmp);
        std::vector<int> dp(n);
        std::vector<int> height(n + 1, INT_MAX);

        for (int i = 0; i < n; i++) {
            int k = std::lower_bound(height.begin(), height.end(), envelopes[i][1]) - height.begin();
            dp[i] = k;
            height[k] = envelopes[i][1];
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = std::max(ans, dp[i]);
        }

        return ans + 1;
    }

    static bool cmp(const std::vector<int>& x, const std::vector<int>& y) {
        return x[0] != y[0] ? x[0] < y[0] : x[1] > y[1];
    }
};


#endif