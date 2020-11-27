#ifndef __LINTCODE_0040__
#define __LINTCODE_0040__

#include "data-types.h"

/*@40. Implement Queue by Two Stacks
As the title described, you should only use two stacks to implement a queue's actions.
The queue should support push(element), pop() and top() where pop is pop the first(a.k.a front) element in the queue.
Both pop and top methods should return the value of first element.

Example 1:
    Input:
        push(1)
        pop()
        push(2)
        push(3)
        top()
        pop()
    Output:
        1
        2
        2

Example 2:
    Input:
        push(1)
        push(2)
        push(2)
        push(3)
        push(4)
        push(5)
        push(6)
        push(7)
        push(1)
    Output:
        []

Challenge
    implement it by two stacks, do not use any other data structure and push, pop and top should be O(1) by AVERAGE.

Notice
    Suppose the queue is not empty when the pop() function is called.
*/
class MyQueue40Bully 
{
public:
    MyQueue40Bully() 
    {
        // do intialization if necessary
    }

    /*
     * @param element: An integer
     * @return: nothing
     */
    void push(int element) 
    {
        s1.push(element);
    }

    /*
     * @return: An integer
     */
    int pop() 
    {
        if (s1.empty()) {
            return -1;
        }

        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        int rtn = s2.top();
        s2.pop();
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }

        return rtn;
    }

    /*
     * @return: An integer
     */
    int top() 
    {
        if (s1.empty()) {
            return -1;
        }

        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        int rtn = s2.top();
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }

        return rtn;
    }

private:
    std::stack<int> s1;
    std::stack<int> s2;
};


class MyQueue40 
{
public:
    MyQueue40() 
    {
        // do intialization if necessary
    }

    /*
     * @param element: An integer
     * @return: nothing
     */
    void push(int element) 
    {
        s1.push(element);
    }

    /*
     * @return: An integer
     */
    int pop() 
    {
        if (s2.empty()) {
            move();
        }

        int rtn = s2.top();
        s2.pop();

        return rtn;
    }

    /*
     * @return: An integer
     */
    int top() 
    {
        if (s2.empty()) {
            move();
        }

        return s2.top();
    }

    void move() 
    {
        if (!s2.empty() || s1.empty()) {
            return;
        }

        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }

private:
    std::stack<int> s1;
    std::stack<int> s2;
};

#endif

