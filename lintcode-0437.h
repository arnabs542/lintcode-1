
#ifndef __LINTCODE_0437__
#define __LINTCODE_0437__

#include "data-types.h"


/*@437. Copy Books
Given n books and the i-th book has pages[i] pages. There are k persons to copy these books.
These books list in a row and each person can claim a continous range of books.
For example, one copier can copy the books from i-th to j-th continously, but he can not copy the 1st book, 2nd book and 4th book (without 3rd book).
They start copying books at the same time and they all cost 1 minute to copy 1 page of a book.
What's the best strategy to assign books so that the slowest copier can finish at earliest time?
Return the shortest time that the slowest copier spends.

Example 1:
    Input: pages = [3, 2, 4], k = 2
    Output: 5
    Explanation:
        First person spends 5 minutes to copy book 1 and book 2.
        Second person spends 4 minutes to copy book 3.

Example 2:
    Input: pages = [3, 2, 4], k = 3
    Output: 4
    Explanation: Each person copies one of the books.

Challenge
    O(nk) time

Notice
    The sum of book pages is less than or equal to 2147483647
*/
class Solution437DoublePointers {
public:
    /**
     * @param pages: an array of integers
     * @param k: An integer
     * @return: an integer
     */
    int copyBooks(std::vector<int>& pages, int k) {
        if (pages.empty() || k < 0) {
            return 0;
        }

        int sum = getSum(pages);

        int start = 0, end = sum;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (getNumberOfCopiers(pages, mid) <= k) {
                end = mid;
            }
            else {
                start = mid;
            }
        }

        if (getNumberOfCopiers(pages, start) <= k) {
            return start;
        }

        return end;
    }

private:
    int getSum(std::vector<int>& pages) {
        int sum = 0;
        for (auto page : pages) {
            sum += page;
        }

        return sum;
    }

    int getNumberOfCopiers(std::vector<int>& pages, int limit) {
        int copiers = 0;
        int lastcopied = limit;

        for (int page : pages) {
            if (page > limit) {
                return INT_MAX;
            }

            if (lastcopied + page > limit) {
                copiers++;
                lastcopied = 0;
            }
            lastcopied += page;
        }

        return copiers;
    }
};

class Solution437DP {
public:
    /**
     * @param pages: an array of integers
     * @param k: An integer
     * @return: an integer
     */
    int copyBooks(std::vector<int>& pages, int k) {
        if (pages.empty() || k < 0) {
            return 0;
        }

        int n = pages.size();

        std::vector<int> prefixSum(n + 1);
        for (int i = 1; i <= n; i++) {
            prefixSum[i] = prefixSum[i - 1] + pages[i - 1];
        }

        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(k + 1));
        for (int i = 1; i <= n; i++) {
            dp[i][0] = INT_MAX;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                dp[i][j] = INT_MAX;
                for (int prev = 0; prev < i; prev++) {
                    int cost = prefixSum[i] - prefixSum[prev];
                    dp[i][j] = std::min(dp[i][j], std::max(dp[prev][j - 1], cost));
                }
            }
        }

        return dp[n][k];
    }
};

#endif

