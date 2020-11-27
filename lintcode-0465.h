#ifndef __LINTCODE_0465__
#define __LINTCODE_0465__

#include "data-types.h"

/*@465. Kth Smallest Sum In Two Sorted Arrays
Given two integer arrays sorted in ascending order and an integer k. 
Define sum = a + b, where a is an element from the first array and b is an element from the second one. 
Find the kth smallest sum out of all possible sums.

Example 1
    Input:
        a = [1, 7, 11]
        b = [2, 4, 6]
        k = 3
    Output: 7
        Explanation: The sums are [3, 5, 7, 9, 11, 13, 13, 15, 17] and the 3th is 7.

Example 2
    Input:
        a = [1, 7, 11]
        b = [2, 4, 6]
        k = 4
    Output: 9
        Explanation: The sums are [3, 5, 7, 9, 11, 13, 13, 15, 17] and the 4th is 9.

Example 3
    Input:
        a = [1, 7, 11]
        b = [2, 4, 6]
        k = 8
    Output: 15
        Explanation: The sums are [3, 5, 7, 9, 11, 13, 13, 15, 17] and the 8th is 15.
Challenge
    Do it in either of the following time complexity:
        O(k log min(n, m, k)). where n is the size of A, and m is the size of B.
        O( (m + n) log maxValue). where maxValue is the max number in A and B.

*/
class Solution465Bully 
{
public:
    /**
     * @param A: an integer arrays sorted in ascending order
     * @param B: an integer arrays sorted in ascending order
     * @param k: An integer
     * @return: An integer
     */
    int kthSmallestSum(std::vector<int>& A, std::vector<int>& B, int k) {
        if (A.empty() || B.empty() || k < 0) {
            return -1;
        }

        std::vector<int> sumSets;

        int n = A.size(), m = B.size();
        for (int i = 0; i < A.size(); i++) {
            int sum = 0;
            for (int j = 0; j < B.size(); j++) {
                sumSets.push_back(A[i] + B[j]);
            }
        }

        std::sort(sumSets.begin(), sumSets.end());

        return sumSets[k - 1];
    }
};

class Solution465DoublePointer 
{
public:
    /**
     * @param A: an integer arrays sorted in ascending order
     * @param B: an integer arrays sorted in ascending order
     * @param k: An integer
     * @return: An integer
     */
    int kthSmallestSum(std::vector<int>& A, std::vector<int>& B, int k) {
        if (A.empty() || B.empty() || k < 0) {
            return -1;
        }

        int n = A.size(), m = B.size();

        int left = A[0] + B[0] - 1;
        int right = A[n - 1] + B[m - 1] + 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (calc(mid, A, B) >= k) {
                right = mid;
            }
            else {
                left = mid;
            }
        }

        return right;
    }

private:
    int calc(int x, std::vector<int>& A, std::vector<int>& B) {
        int n = A.size(), m = B.size();
        int num = 0;

        int start = 0, end = m - 1;
        while (start <= n - 1) {
            while (end >= 0) {
                if (A[start] + B[end] > x) {
                    end -= 1;
                }
                else {
                    break;
                }
            }

            num += end + 1;
            start += 1;
        }

        return num;
    }
};

#endif
