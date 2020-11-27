#ifndef __LINTCODE_0414__
#define __LINTCODE_0414__

#include "data-types.h"

/*@414. Divide Two Integers
Divide two integers without using multiplication, division and mod operator.

If it will overflow(exceeding 32-bit signed integer representation range), return 2147483647

The integer division should truncate toward zero.

Example
Example 1:

Input: dividend = 0, divisor = 1
Output: 0
Example 2:

Input: dividend = 100, divisor = 9
Output: 11
*/
class Solution414 
{
public:
    /**
     * @param dividend: the dividend
     * @param divisor: the divisor
     * @return: the result
     */
    int divide(int dividend, int divisor) 
    {
        bool isNegative = false;
        if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) {
            isNegative = true;
        }

        long long ans = 0;
        long long Dividend = abs((long long)(dividend));
        long long Dividor = abs((long long)(divisor));

        while (Dividend >= Dividor) {
            long long temp = Dividor;
            long long cnt = 1;

            while (Dividend >= temp) {
                Dividend -= temp;
                ans += cnt;

                cnt = cnt << 1;
                temp = temp << 1;
            }
        }

        if (isNegative) {
            ans = -ans;
        }

        if (ans < INT_MIN || ans > INT_MAX) {
            return INT_MAX;
        }

        return (int)ans;
    }
};

#endif

