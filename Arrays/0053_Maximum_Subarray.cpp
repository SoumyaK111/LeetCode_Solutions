/*
Problem: 53. Maximum Subarray
Difficulty: Medium

Topic:
- Arrays
- Dynamic Programming

Pattern:
- Kadane's Algorithm

Problem Statement:
Given an integer array nums, find the contiguous subarray
(with at least one element) that has the largest sum and
return its sum.

Approach:
- Traverse the array while maintaining a running sum
  (currSum).
- Add each element to currSum.
- Update maxSum whenever currSum becomes larger than the
  current maximum.
- If currSum becomes negative, reset it to 0 because a
  negative prefix cannot contribute to a larger future sum.

Why It Works:
A negative running sum will only decrease the sum of any
subarray that follows it. Resetting the running sum allows
the algorithm to start a new subarray from the next element,
ensuring the maximum possible sum is considered.

Time Complexity:
O(n) - The array is traversed exactly once.

Space Complexity:
O(1) - Only two integer variables are used.
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0;
        int maxSum = INT_MIN;

        for (int val : nums) {
            currSum += val;
            maxSum = max(currSum, maxSum);

            if (currSum < 0) {
                currSum = 0;
            }
        }

        return maxSum;
    }
};