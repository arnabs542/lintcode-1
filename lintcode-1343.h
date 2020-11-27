#ifndef __LINTCODE_1343__
#define __LINTCODE_1343__

#include "data-types.h"

/*@1343. Sum of Two Strings
Given you two strings which are only contain digit character. you should return the sum of each digit as string

Example1:
    Input:
        A = "99"
        B = "111"
        Output: "11010"
        Explanation: because 9 + 1 = 10, 9 + 1 = 10, 0 + 1 = 1,connect them,so answer is "11010"
Example2:
    Input:
        A = "2"
        B = "321"
        Output: "323"
        Explanation: because 2 + 1 = 3, 2 + 0 = 2, 3 + 0 = 3, connect them,so answer is "323"
Notice
    A and B are strings which are composed of numbers
*/
class Solution1343 
{
public:
    /**
     * @param A: a string
     * @param B: a string
     * @return: return the sum of two strings
     */
    std::string SumofTwoStrings(std::string& A, std::string& B) {
        if (A.empty() || B.empty()) {
            return A.empty() == true ? A : A;
        }

        std::string result;

        int i = A.size() - 1;
        int j = B.size() - 1;

        while (i >= 0 && j >= 0) {
            result.insert(0, std::to_string(stoi(A.substr(i, 1)) + stoi(B.substr(j, 1))));
            i--;
            j--;
        }

        if (i >= 0) {
            result = A.substr(0, i + 1) + result;
        }

        if (j >= 0) {
            result = B.substr(0, j + 1) + result;
        }

        return result;
    }
};

class Solution1343Method2 
{
public:
    /**
     * @param A: a string
     * @param B: a string
     * @return: return the sum of two strings
     */
    std::string SumofTwoStrings(std::string& A, std::string& B) {
        if (A.empty() || B.empty()) {
            return A.empty() == true ? A : A;
        }

        std::string result;

        int i = A.size() - 1;
        int j = B.size() - 1;

        while (i >= 0 && j >= 0) {
            result = std::to_string((A[i] - '0') + (B[j] - '0')) + result;
            i--;
            j--;
        }

        if (i >= 0) {
            result = A.substr(0, i + 1) + result;
        }

        if (j >= 0) {
            result = B.substr(0, j + 1) + result;
        }

        return result;
    }
};


#endif
