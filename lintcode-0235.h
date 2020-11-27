#ifndef __LINTCODE_0235__
#define __LINTCODE_0235__

#include "data-types.h"


/*@235. Prime Factorization
Prime factorize a given integer.

Example
Example 1:

Input: 10
Output: [2, 5]
Example 2:

Input: 660
Output: [2, 2, 3, 5, 11]
Notice
You should sort the factors in ascending order.
*/
class Solution235 
{
public:
    /**
     * @param num: An integer
     * @return: an integer array
     */
    std::vector<int> primeFactorization(int num) 
    {
        std::vector<int> result;

        int up = (int)sqrt(num);
        for (int k = 2; k <= up && num > 1; k++) {
            while (num % k == 0) {
                num = num / k;
                result.push_back(k);
            }
        }

        if (num > 1) {
            result.push_back(num);
        }

        return result;
    }
};

#endif
