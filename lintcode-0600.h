#ifndef __LINTCODE_0606__
#define __LINTCODE_0600__

#include "data-types.h"

/*@600. Smallest Rectangle Enclosing Black Pixels
An image is represented by a binary matrix with 0 as a white pixel and 1 as a black pixel. The black pixels are connected,
i.e., there is only one black region. Pixels are connected horizontally and vertically. Given the location (x, y) of one of the black pixels,
return the area of the smallest (axis-aligned) rectangle that encloses all black pixels.

Example
    Input:["0010","0110","0100"],x=0,y=2
    Output:6
    Explanation:
        The upper left coordinate of the matrix is (0,1), and the lower right coordinate is (2,2).
Example 2:
    Input:["1110","1100","0000","0000"], x = 0, y = 1
    Output:6
    Explanation:
        The upper left coordinate of the matrix is (0, 0), and the lower right coordinate is (1,2).
*/
class Solution600BFS {
public:
    /**
     * @param image: a binary matrix with '0' and '1'
     * @param x: the location of one of the black pixels
     * @param y: the location of one of the black pixels
     * @return: an integer
     */
    int minArea(std::vector<std::vector<char>>& image, int x, int y) {
        if (image.empty() || image[0].empty()) {
            return 0;
        }

        int n = image.size(), m = image[0].size();

        std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));
        std::queue<std::pair<int, int>> q;
        q.push({ x,y });
        visited[x][y] = true;

        std::vector<std::pair<int, int>> delta = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

        int minX = n - 1, maxX = 0;
        int minY = m - 1, maxY = 0;

        while (!q.empty()) {
            std::pair<int, int> curr = q.front();
            q.pop();

            minX = minX < curr.first ? minX : curr.first;
            maxX = maxX > curr.first ? maxX : curr.first;
            minY = minY < curr.second ? minY : curr.second;
            maxY = maxY > curr.second ? maxY : curr.second;

            for (auto p : delta) {
                int nx = curr.first + p.first;
                int ny = curr.second + p.second;

                if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] || image[nx][ny] == '0') {
                    continue;
                }

                visited[nx][ny] = true;
                q.push({ nx, ny });
            }
        }

        return (maxX - minX + 1) * (maxY - minY + 1);
    }
};

class Solution600DoublePointers {
public:
    /**
     * @param image: a binary matrix with '0' and '1'
     * @param x: the location of one of the black pixels
     * @param y: the location of one of the black pixels
     * @return: an integer
     */
    int minArea(std::vector<std::vector<char>>& image, int x, int y) {
        if (image.empty() || image[0].empty()) {
            return 0;
        }

        int n = image.size(), m = image[0].size();

        int left = findLeft(image, 0, y);
        int right = findRight(image, y, m - 1);
        int top = findTop(image, 0, x);
        int bottom = findBottom(image, x, n - 1);

        return (right - left + 1) * (bottom - top + 1);
    }

private:
    int findLeft(std::vector<std::vector<char>>& image, int start, int end) {
        while (start + 1 < end) {
            int mid = (start + end) / 2;
            if (isEmptyColumn(image, mid)) {
                start = mid;
            }
            else {
                end = mid;
            }
        }

        if (isEmptyColumn(image, start)) {
            return end;
        }

        return start;
    }

    int findRight(std::vector<std::vector<char>>& image, int start, int end) {
        while (start + 1 < end) {
            int mid = (start + end) / 2;
            if (isEmptyColumn(image, mid)) {
                end = mid;
            }
            else {
                start = mid;
            }
        }

        if (isEmptyColumn(image, end)) {
            return start;
        }

        return end;
    }

    int findTop(std::vector<std::vector<char>>& image, int start, int end) {
        while (start + 1 < end) {
            int mid = (start + end) / 2;
            if (isEmptyRow(image, mid)) {
                start = mid;
            }
            else {
                end = mid;
            }
        }

        if (isEmptyRow(image, start)) {
            return end;
        }

        return start;
    }

    int findBottom(std::vector<std::vector<char>>& image, int start, int end) {
        while (start + 1 < end) {
            int mid = (start + end) / 2;
            if (isEmptyRow(image, mid)) {
                end = mid;
            }
            else {
                start = mid;
            }
        }

        if (isEmptyRow(image, end)) {
            return start;
        }

        return end;
    }

    bool isEmptyColumn(std::vector<std::vector<char>>& image, int col) {
        for (int i = 0; i < (int)image.size(); i++) {
            if (image[i][col] == '1') {
                return false;
            }
        }

        return true;
    }

    bool isEmptyRow(std::vector<std::vector<char>>& image, int row) {
        for (int i = 0; i < (int)image[0].size(); i++) {
            if (image[row][i] == '1') {
                return false;
            }
        }

        return true;
    }
};

#endif

