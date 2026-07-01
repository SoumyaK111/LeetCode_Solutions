/*
Problem: 283. Move Zeroes
Difficulty: Easy

Topic:
- Arrays
- Two Pointers

Pattern:
- Two Pointers

Problem Statement:
Given an integer array nums, move all 0's to the end while
maintaining the relative order of the non-zero elements.
The operation must be performed in-place without making a
copy of the array.

Approach:
- Maintain two pointers:
    - scan: Traverses every element in the array.
    - write: Tracks the position where the next non-zero
      element should be placed.
- Traverse the array using the scan pointer.
- Whenever a non-zero element is found:
    - Swap it with the element at the write pointer.
    - Increment the write pointer.
- By the end of the traversal:
    - All non-zero elements are placed at the beginning
      in their original order.
    - All zeroes naturally move to the end.

Why It Works:
The write pointer always points to the first available
position for a non-zero element.

Whenever a non-zero element is encountered, swapping it
with the write position preserves the relative order of
all non-zero elements while pushing zeroes toward the end.

Time Complexity:
O(n) - The array is traversed exactly once.

Space Complexity:
O(1) - No extra array is used.
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int write = 0, scan = 0;

        for (scan = 0; scan < nums.size(); scan++) {

            if (nums[scan] != 0) {
                swap(nums[scan], nums[write]);
                write++;
            }
        }
    }
};
