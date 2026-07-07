/*
Problem: 33. Search in Rotated Sorted Array
Difficulty: Medium

Topic:
- Arrays

Pattern:
- Binary Search
- Modified Binary Search

Problem Statement:
Given a sorted array that has been rotated at an unknown
pivot, search for a target value and return its index.
If the target does not exist, return -1.

The solution must run in O(log n) time.

Approach:
- Initialize two pointers:
    - st = 0
    - end = n - 1
- While st <= end:
    - Find the middle element.
    - If nums[mid] is the target, return its index.
    - Determine which half is sorted:
        1. Left half is sorted if:
           nums[st] <= nums[mid]
        2. Otherwise, the right half is sorted.
    - Check whether the target lies within the sorted half.
        - If yes, discard the other half.
        - Otherwise, search the remaining half.
- If the loop finishes, return -1.

Why It Works:
Although the array is rotated, at least one half of the
array is always sorted.

By identifying the sorted half and checking whether the
target lies within its range, we can safely eliminate half
of the search space in every iteration.

Thus, Binary Search is preserved with O(log n) time.

Time Complexity:
O(log n) - Half of the search space is discarded every iteration.

Space Complexity:
O(1) - Uses constant extra space.

Explanation :
"A rotated sorted array still has one important property: at least
one half of the array is always sorted. During each binary search 
iteration, I first check whether the middle element is the target. 
If not, I determine whether the left or right half is sorted by comparing
nums[st] and nums[mid]. Once I know the sorted half, I check if the
target falls within its range. If it does, I continue searching there;
otherwise, I search the other half. Since one half is discarded in every 
iteration, the time complexity remains O(log n)."
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int st = 0;
        int end = nums.size() - 1;

        while (st <= end) {

            int mid = st + (end - st) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            // Left half is sorted
            if (nums[st] <= nums[mid]) {

                if (nums[st] <= target && target < nums[mid]) {
                    end = mid - 1;
                }
                else {
                    st = mid + 1;
                }
            }

            // Right half is sorted
            else {

                if (nums[mid] < target && target <= nums[end]) {
                    st = mid + 1;
                }
                else {
                    end = mid - 1;
                }
            }
        }

        return -1;
    }
};