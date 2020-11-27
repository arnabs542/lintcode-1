#ifndef __LINTCODE_0187__
#define __LINTCODE_0187__

#include "data-types.h"

/*@187: Gas Station
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1).
You begin the journey with an empty tank at one of the gas stations.
Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Example 1:
    Input:gas[i]=[1,1,3,1],cost[i]=[2,2,1,1]
    Output:2

Example 2:
    Input:gas[i]=[1,1,3,1],cost[i]=[2,2,10,1]
    Output:-1

Challenge
    O(n) time and O(1) extra space

Notice
    The solution is guaranteed to be unique.
*/
class Solution187
{
public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost)
    {
        if (gas.empty() || cost.empty() || gas.size() != cost.size()) {
            return -1;
        }

        for (int i = 0; i < (int)gas.size(); i++) {
            if (gas[i] < cost[i]) {
                continue;
            }

            if (canLoop(gas, cost, i)) {
                return i;
            }
        }

        return -1;
    }

private:
    bool canLoop(std::vector<int>& gas, std::vector<int>& cost, int startIdx) 
    {
        int totalGas = 0;
        int Length = gas.size();

        for (int i = startIdx; i < Length + startIdx; i++) {
            totalGas += gas[i % Length] - cost[i % Length];
            if (totalGas < 0) {
                return false;
            }
        }

        return true;
    }
};

#endif

