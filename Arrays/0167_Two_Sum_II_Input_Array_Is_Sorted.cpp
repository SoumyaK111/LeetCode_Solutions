/*

Problem: 167. Two Sum II - Input Array Is Sorted
Difficulty: Medium

Topic:
- Arrays
- Two Pointers

Pattern:
- Two Pointer Technique

Problem Statement:
Given a 1-indexed array of integers sorted in non-decreasing
order, find two numbers such that they add up to a target.
Return their 1-based indices.

Approach:
- Initialize two pointers:
    - i at the beginning of the array.
    - j at the end of the array.
- Compute the sum of numbers[i] and numbers[j].
- If the sum is greater than the target, decrement j.
- If the sum is less than the target, increment i.
- If the sum equals the target, return the 1-based indices.

Why It Works:
Since the array is already sorted:
- Moving the left pointer to the right increases the sum.
- Moving the right pointer to the left decreases the sum.
This allows us to efficiently search for the target sum in
a single traversal without using extra space.

Time Complexity:
O(n) - Each pointer moves at most n times.

Space Complexity:
O(1) - Only constant extra space is used.
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int n = numbers.size();

        int i = 0;
        int j = n - 1;

        while (i < j) {
            int pairSum = numbers[i] + numbers[j];

            if (pairSum > target) {
                j--;
            }
            else if (pairSum < target) {
                i++;
            }
            else {
                ans.push_back(i + 1);
                ans.push_back(j + 1);
                return ans;
            }
        }

        return {};
    }
};

