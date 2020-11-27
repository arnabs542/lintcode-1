#ifndef __LINTCODE_0433__
#define __LINTCODE_0433__

#include "data-types.h"

/*@433. Number of Islands
Given a boolean 2D matrix, 0 is represented as the sea, 1 is represented as the island.
If two 1 is adjacent, we consider them in the same island.
We only consider up/down/left/right adjacent.

Find the number of islands.

Example 1:
	Input:
		[
		  [1,1,0,0,0],
		  [0,1,0,0,1],
		  [0,0,0,1,1],
		  [0,0,0,0,0],
		  [0,0,0,0,1]
		]
	Output:	3

Example 2:
	Input:
		[
		  [1,1]
		]
	Output:1
*/
class Solution433
{
public:
	int numIslands(std::vector<std::vector<bool>>& grid)
	{
		if (grid.empty() || grid[0].empty()) {
			return 0;
		}

		int row = grid.size(), column = grid[0].size();
		std::vector<std::vector<bool>> visited(row, std::vector<bool>(column, false));

		std::vector<std::pair<int, int>> points = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };
		std::queue<std::pair<int, int>> q;

		int island = 0;

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				if (!grid[i][j] || visited[i][j]) {
					continue;
				}

				island++;
				q.push({ i, j });
				while (!q.empty()) {
					std::pair<int, int> curr = q.front();
					q.pop();

					for (auto p : points) {
						int nx = curr.first + p.first;
						int ny = curr.second + p.second;

						if (nx < 0 || nx >= row || ny < 0 || ny >= column || !grid[nx][ny] || visited[nx][ny]) {
							continue;
						}
						q.push({ nx, ny });
						visited[nx][ny] = true;
					}
				}

			}
		}
		return island;
	}
};

class Solution433_1
{
public:
	int numIslands(std::vector<std::vector<bool>>& grid)
	{
		if (grid.empty() || grid[0].empty()) {
			return 0;
		}

		int row = grid.size(), column = grid[0].size();
		std::vector<std::vector<bool>> visited(row, std::vector<bool>(column, false));
		int island = 0;

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				if (!grid[i][j] || visited[i][j]) {
					continue;
				}
				island++;
				bfs(i, j, grid, visited);
			}
		}
		return island;
	}

private:
	void bfs(int x, int y, std::vector<std::vector<bool>>& grid, std::vector<std::vector<bool>>& visited)
	{
		std::vector<std::pair<int, int>> points = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };
		std::queue<std::pair<int, int>> q;

		int row = grid.size(), column = grid[0].size();
		q.push({ x, y });
		visited[x][y] = true;
		while (!q.empty()) {
			std::pair<int, int> curr = q.front();
			q.pop();

			for (auto p : points) {
				int nx = curr.first + p.first;
				int ny = curr.second + p.second;

				if (nx < 0 || nx >= row || ny < 0 || ny >= column || !grid[nx][ny] || visited[nx][ny]) {
					continue;
				}

				q.push({ nx, ny });
				visited[nx][ny] = true;
			}
		}
	}
};

#endif

