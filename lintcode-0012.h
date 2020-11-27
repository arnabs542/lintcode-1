#ifndef __LINTCODE_0012__
#define __LINTCODE_0012__

#include "data-types.h"

/*@12. Min Stack
Implement a stack with following functions:
    push(val) push val into the stack
    pop() pop the top element and return it
    min() return the smallest number in the stack
    All above should be in O(1) cost.

Example 1:
    Input:
      push(1)
      pop()
      push(2)
      push(3)
      min()
      push(1)
      min()
    Output:
      1
      2
      1

Example 2:
    Input:
      push(1)
      min()
      push(2)
      min()
      push(3)
      min()
    Output:
      1
      1
      1

Notice
    min() will never be called when there is no number in the stack.
*/
class MinStack12 
{
public:
    MinStack12() 
    {
        // do intialization if necessary
    }

    /*
     * @param number: An integer
     * @return: nothing
     */
    void push(int number) 
    {
        // write your code here
        mainS.push(number);

        if (minS.empty() || minS.top() > number) {
            minS.push(number);
        }
        else {
            minS.push(minS.top());
        }
    }

    /*
     * @return: An integer
     */
    int pop() 
    {
        // write your code here
        int rtn = mainS.top();
        mainS.pop();
        minS.pop();

        return rtn;
    }

    /*
     * @return: An integer
     */
    int min() 
    {
        // write your code here
        return minS.top();
    }

private:
    std::stack<int> mainS;
    std::stack<int> minS;
};


#endif

