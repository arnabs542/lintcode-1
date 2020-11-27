#ifndef __LINTCODE_0859__
#define __LINTCODE_0859__

#include "data-types.h"


/*@859. Max Stack
Design a max stack that supports push, pop, top, peekMax and popMax.
    push(x) -- Push element x onto stack.
    pop() -- Remove the element on top of the stack and return it.
    top() -- Get the element on the top.
    peekMax() -- Retrieve the maximum element in the stack.
    popMax() -- Retrieve the maximum element in the stack, and remove it. If you find more than one maximum elements, only remove the top-most one.

Example
    Input:
        push(5)
        push(1)
        push(5)
        top()
        popMax()
        top()
        peekMax()
        pop()
        top()
    Output:
        5
        5
        1
        5
        1
        5
Notice
    -1e7 <= x <= 1e7
    Number of operations won't exceed 10000.
    The last four operations won't be called when stack is empty.
*/
class Solution859 
{
public:
    Solution859() {
        // do intialization if necessary
    }

    /*
     * @param number: An integer
     * @return: nothing
     */
    void push(int number) 
    {
        mainS.push(number);

        if (maxS.empty() || maxS.top() < number) {
            maxS.push(number);
        }
        else {
            maxS.push(maxS.top());
        }
    }

    /*
     * @return: An integer
     */
    int pop() 
    {
        int rtn = mainS.top();
        mainS.pop();
        maxS.pop();

        return rtn;
    }

    /*
     * @return: An integer
     */
    int top() 
    {
        return mainS.top();
    }

    /*
     * @return: An integer
     */
    int peekMax() 
    {
        return maxS.top();
    }

    /*
     * @return: An integer
     */
    int popMax() 
    {
        std::stack<int> tmpS;

        int max = maxS.top();
        maxS.pop();
        while (!mainS.empty() && mainS.top() < max) {
            tmpS.push(mainS.top());
            mainS.pop();
        }
        mainS.pop();
        while (!tmpS.empty()) {
            mainS.push(tmpS.top());
            tmpS.pop();
        }

        return max;
    }

private:
    std::stack<int> mainS;
    std::stack<int> maxS;
};

#endif
