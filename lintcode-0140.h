#ifndef __LINTCODE_0140__
#define __LINTCODE_0140__

#include "data-types.h"

/*@140. Fast Power
Calculate the a^n % b where a, b and n are all 32bit non-negative integers.

Example
For 2^31 % 3 = 2

For 1001000 % 1000 = 0

Challenge
O(logn)
*/
class Solution140 
{
public:
    /**
     * @param a: A 32bit integer
     * @param b: A 32bit integer
     * @param n: A 32bit integer
     * @return: An integer
     */
    int fastPower(int a, int b, int n) 
    {
        if (n == 1) {
            return a % b;
        }

        if (n == 0) {
            return 1 % b;
        }

        long product = fastPower(a, b, n / 2);
        product = product * product % b;
        if (n % 2 == 1) {
            product = (product * a) % b;
        }

        return (int)product;
    }
};

#endif

