/*
Problem: 704. Binary Search
Difficulty: Easy

Topic:
- Arrays

Pattern:
- Binary Search

Problem Statement:
Given a sorted array of unique integers and a target
value, return its index if found. Otherwise, return -1.

The solution must have O(log n) time complexity.

Approach:
- Initialize two pointers:
    - st = 0
    - end = n - 1
- While st <= end:
    - Compute the middle index using:
        mid = st + (end - st) / 2
    - If nums[mid] equals the target:
        - Return mid.
    - If target is greater:
        - Search the right half.
    - Otherwise:
        - Search the left half.
- If the loop ends, the target does not exist.
  Return -1.

Why It Works:
Since the array is sorted, comparing the target with the
middle element allows us to eliminate half of the search
space after every comparison.

Each iteration reduces the search interval by half,
resulting in logarithmic time complexity.

Time Complexity:
O(log n) - Search space is halved in every iteration.

Space Complexity:
O(1) - Uses only constant extra space.

Explanation :
"Since the array is sorted, I can apply binary search.
I maintain two pointers representing the current search
range. In each iteration, I compute the middle index using
st + (end - st) / 2 to avoid integer overflow. If the middle
element matches the target, I return its index. Otherwise,
I discard the half of the array that cannot contain the target
based on the comparison. Repeating this process halves the
search space each time, resulting in O(log n) time complexity."
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int st = 0;
        int end = nums.size() - 1;

        while (st <= end) {

            int mid = st + (end - st) / 2; // Prevent integer overflow

            if (target > nums[mid]) {
                st = mid + 1;
            }
            else if (target < nums[mid]) {
                end = mid - 1;
            }
            else {
                return mid;
            }
        }
        return -1;
    }
};