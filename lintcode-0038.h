
#ifndef __LINTCODE_0038__
#define __LINTCODE_0038__

#include "data-types.h"

/*@38. Search a 2D Matrix II
Write an efficient algorithm that searches for a value in an m x n matrix, return the occurrence of it.
This matrix has the following properties:
Integers in each row are sorted from left to right.
Integers in each column are sorted from up to bottom.
No duplicate integers in each row or column.

Example 1:
    Input:
        [[3,4]]
        target=3
    Output:1

Example 2:
    Input:
        [
          [1, 3, 5, 7],
          [2, 4, 7, 8],
          [3, 5, 9, 10]
        ]
        target = 3
    Output:2

Challenge
    O(m+n) time and O(1) extra space
*/
class Solution38 {
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        int n = (int)matrix.size(), m = (int)matrix[0].size();
        int i = n - 1, j = 0, cnt = 0;
        while (i >= 0 && j < m) {
            if (matrix[i][j] == target) {
                i--;
                j++;
                cnt++;

            }
            else if (matrix[i][j] < target) {
                j++;

            }
            else {
                i--;
            }
        }

        return cnt;
    }
};

#endif

