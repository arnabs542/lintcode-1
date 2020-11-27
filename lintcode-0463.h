#ifndef __LINTCODE_0463__
#define __LINTCODE_0463__

#include "data-types.h"

/*@463. Sort Integers
Given an integer array, sort it in ascending order. Use selection sort, bubble sort, insertion sort or any O(n2) algorithm.

Example 1:
    Input:  [3, 2, 1, 4, 5]
    Output: [1, 2, 3, 4, 5]
    Explanation:
    return the sorted array.

Example 2:
    Input:  [1, 1, 2, 1, 1]
    Output: [1, 1, 1, 1, 2]
    Explanation:
    return the sorted array.
*/
class Solution463MergeSort 
{
public:
    /**
     * @param A: an integer array
     * @return: nothing
     */
    void sortIntegers(std::vector<int>& A) 
    {
        if (A.empty()) {
            return;
        }

        std::vector<int> temp(A.size());

        mergeSort(A, 0, A.size() - 1, temp);
    }
private:
    void mergeSort(std::vector<int>& A, int start, int end, std::vector<int>& temp) 
    {
        if (start >= end) {
            return;
        }

        int mid = start + (end - start) / 2;

        mergeSort(A, start, mid, temp);
        mergeSort(A, mid + 1, end, temp);

        merge(A, start, end, temp);
    }

    void merge(std::vector<int>& A, int start, int end, std::vector<int>& temp) 
    {

        int mid = start + (end - start) / 2;
        int left = start, right = mid + 1, idx = start;

        while (left <= mid && right <= end) {
            if (A[left] < A[right]) {
                temp[idx++] = A[left++];
            }
            else {
                temp[idx++] = A[right++];
            }
        }

        while (left <= mid) {
            temp[idx++] = A[left++];
        }

        while (right <= end) {
            temp[idx++] = A[right++];
        }

        for (int i = start; i <= end; i++) {
            A[i] = temp[i];
        }
    }
};

class Solution463HeapSort
{
public:
    void sortIntegers(std::vector<int>& A)
    {
        if (A.empty()) {
            return;
        }

        heapify(A);
        for (int i = A.size() - 1; i >= 0; i--) {
            std::swap(A[0], A[i]);
            siftDown(A, 0, i - 1);
        }
    }

private:
    void heapify(std::vector<int>& A)
    {
        for (int i = (A.size() - 1) / 2; i >= 0; i--) {
            siftDown(A, i, A.size() - 1);
        }
    }

    void siftDown(std::vector<int>& A, int left, int right)
    {
        int k = left;
        while (k * 2 + 1 <= right) {
            int son = k * 2 + 1;
            if (k * 2 + 2 <= right && A[son] < A[k * 2 + 2]) {
                son = k * 2 + 2;
            }
            if (A[son] <= A[k]) {
                break;
            }

            std::swap(A[son], A[k]);
            k = son;
        }
    }

};

#endif

