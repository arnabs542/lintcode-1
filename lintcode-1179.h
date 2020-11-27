#ifndef __LINTCODE_1179__
#define __LINTCODE_1179__

#include "data-types.h"

/*@1179. Friend Circles
There are N students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature.
For example, if A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C.
			 And we defined a friend circle is a group of students who are direct or indirect friends.

Given a N*N matrix M representing the friend relationship between students in the class.
If M[i][j] = 1, then the ith and jth students are direct friends with each other, otherwise not.
And you have to output the total number of friend circles among all the students.

Example
	Input: [[1,1,0],[1,1,0],[0,0,1]]
	Output: 2
	Explanation:
		The 0th and 1st students are direct friends, so they are in a friend circle.
		The 2nd student himself is in a friend circle. So return 2.

Example 2:
	Input: [[1,1,0],[1,1,1],[0,1,1]]
	Output: 1
	Explanation:
		The 0th and 1st students are direct friends, the 1st and 2nd students are direct friends,
		so the 0th and 2nd students are indirect friends. All of them are in the same friend circle, so return 1.

Notice
	1. 1<=N<=200.
	2. M[i][i] = 1 for all students.
	3. If M[i][j] = 1, then M[j][i] = 1.
*/
class Solution1179
{
public:
	int findCircleNum(std::vector<std::vector<int>>& M)
	{
		if (M.empty() || M[0].empty()) {
			return 0;
		}

		int ans = 0;
		std::vector<bool> visited(M.size(), false);
		std::queue<int> q;

		for (int i = 0; i < (int)M.size(); i++) {
			if (visited[i]) {
				continue;
			}

			ans++;
			q.push(i);
			visited[i] = true;

			while (!q.empty()) {
				int curr = q.front();
				q.pop();

				for (int j = 0; j < (int)M.size(); j++) {
					if (visited[j] || M[curr][j] == 0) {
						continue;
					}
					q.push(j);
					visited[j] = true;
				}
			}
		}

		return ans;
	}
};

#endif

