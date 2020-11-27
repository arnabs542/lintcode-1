
#ifndef __LINTCODE_0028__
#define __LINTCODE_0028__


#include "data-types.h"

/*@28. Search a 2D Matrix
Write an efficient algorithm that searches for a value in an m x n matrix.
This matrix has the following properties:
Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.

Example 1:
    Input:  [[5]],2
    Output: false
    Explanation: false if not included.

Example 2:
    Input:  [
            [1, 3, 5, 7],
            [10, 11, 16, 20],
            [23, 30, 34, 50]
            ],3
    Output: true
    Explanation: return true if included.

Challenge
    O(log(n) + log(m)) time
*/
class Solution28 {
public:
    /**
     * @param matrix: matrix, a list of lists of integers
     * @param target: An integer
     * @return: a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }

        int n = matrix.size(), m = matrix[0].size();

        int start = 0, end = n * m - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (get(matrix, mid) == target) {
                return true;
            }

            if (get(matrix, mid) < target) {
                start = mid;
            }
            else {
                end = mid;
            }
        }

        if (get(matrix, start) == target || get(matrix, end) == target) {
            return true;
        }

        return false;
    }

private:
    int get(std::vector<std::vector<int>>& matrix, int idx) {
        int x = idx / matrix[0].size();
        int y = idx % matrix[0].size();

        return matrix[x][y];
    }
};


#endif

