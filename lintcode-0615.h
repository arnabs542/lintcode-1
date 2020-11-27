#ifndef __LINTCODE_0615__
#define __LINTCODE_0615__

#include "data-types.h"

/*@615. Course Schedule
There are a total of n courses you have to take, labeled from 0 to n - 1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

Example 1:
	Input: n = 2, prerequisites = [[1,0]]
	Output:true

Example 2:
	Input: n = 2, prerequisites = [[1,0],[0,1]]
	Output: false
*/
class Solution615
{
public:
	bool canFinish(int numCourses, std::vector<std::pair<int, int>>& prerequisites)
	{
		if (prerequisites.empty()) {
			return true;
		}

		std::vector<std::vector<int>> graph(numCourses);
		std::vector<int> inDegree(numCourses);

		// build graph
		for (auto edge : prerequisites) {
			graph[edge.second].push_back(edge.first);
			inDegree[edge.first]++;
		}

		int numChoose = 0;
		std::queue<int> q;
		for (int i = 0; i < numCourses; i++) {
			if (inDegree[i] == 0) {
				q.push(i);
				numChoose++;
			}
		}

		while (!q.empty()) {
			int nowPos = q.front();
			q.pop();

			for (auto nextPos : graph[nowPos]) {
				inDegree[nextPos]--;
				if (inDegree[nextPos] == 0) {
					q.push(nextPos);
					numChoose++;
				}
			}
		}
		return numChoose == numCourses;
	}
};

#endif

