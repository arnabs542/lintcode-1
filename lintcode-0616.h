#ifndef __LINTCODE_0616__
#define __LINTCODE_0616__

#include "data-types.h"

/*@616. Course Schedule II
There are a total of n courses you have to take, labeled from 0 to n - 1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.
There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

Example 1:
	Input: n = 2, prerequisites = [[1,0]]
	Output: [0,1]

Example 2:
	Input: n = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
	Output: [0,1,2,3] or [0,2,1,3]
*/
class Solution616
{
public:
	std::vector<int> findOrder(int numCourses, std::vector<std::pair<int, int>>& prerequisites)
	{
		std::vector<int> result;

		if (prerequisites.empty()) {
			for (int i = 0; i < numCourses; i++) {
				result.emplace_back(i);
			}
			return result;
		}

		std::vector<std::vector<int>> graph(numCourses);
		std::vector<int> inDegree(numCourses);

		for (auto edge : prerequisites) {
			graph[edge.second].emplace_back(edge.first);
			inDegree[edge.first]++;
		}

		std::queue<int> q;
		for (int i = 0; i < numCourses; i++) {
			if (inDegree[i] == 0) {
				q.push(i);
				result.emplace_back(i);
			}
		}

		while (!q.empty()) {
			int nowPos = q.front();
			q.pop();

			for (auto nextPos : graph[nowPos]) {
				inDegree[nextPos]--;
				if (inDegree[nextPos] == 0) {
					q.push(nextPos);
					result.emplace_back(nextPos);
				}
			}
		}

		if (result.size() == numCourses) {
			return result;
		}

		return {};
	}
};

#endif

