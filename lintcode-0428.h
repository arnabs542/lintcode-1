#ifndef __LINTCODE_0428__
#define __LINTCODE_0428__

#include "data-types.h"


/*@428. Pow(x, n)
Implement pow(x, n). (n is an integer.)

Example 1:
    Input: x = 9.88023, n = 3
    Output: 964.498

Example 2:
    Input: x = 2.1, n = 3
    Output: 9.261

Example 3:
    Input: x = 1, n = 0
    Output: 1

Challenge
    O(logn) time

Notice
    You don't need to care about the precision of your answer,
    it's acceptable if the expected answer and your answer 's difference is smaller than 1e-3.
*/
class Solution428 
{
public:
    /**
     * @param x: the base number
     * @param n: the power number
     * @return: the result
     */
    double myPow(double x, int n) {
        bool isNegative = false;

        if (n < 0) {
            x = 1 / x;
            isNegative = true;
            n = -(n + 1);    // avoid overflow when n = INT_MIN.
        }

        double ans = 1, tmp = x;

        while (n != 0) {
            if (n % 2) {
                ans *= tmp;
            }
            tmp *= tmp;
            n = n / 2;
        }

        if (isNegative) {
            ans *= x;
        }

        return ans;
    }
};

#endif
