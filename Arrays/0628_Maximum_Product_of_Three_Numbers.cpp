/*
Problem: 628. Maximum Product of Three Numbers
Difficulty: Easy

Topic:
- Arrays
- Math

Pattern:
- Greedy
- Tracking Extreme Values

Problem Statement:
Given an integer array nums, return the maximum product
that can be obtained by multiplying any three numbers
from the array.

Approach:
- Traverse the array once while maintaining:
    - The three largest numbers:
        max1, max2, max3
    - The two smallest numbers:
        min1, min2
- The maximum product can come from either:
    1. The three largest numbers.
    2. The two smallest (most negative) numbers and the
       largest positive number.
- Return the larger of these two products.

Why It Works:
There are only two possible ways to obtain the maximum
product:

1. Three largest positive numbers.
2. Two negative numbers and the largest positive number.

Multiplying two negative numbers results in a positive
number, which may produce a larger product than using the
second and third largest positive numbers.

By tracking only the required extreme values in one pass,
we avoid sorting the array.

Time Complexity:
O(n) - The array is traversed once.

Space Complexity:
O(1) - Only five integer variables are used.

Explanation :
"The maximum product of three numbers can come from either
the three largest numbers or from the two smallest numbers
together with the largest number, since two negative numbers
produce a positive product. Instead of sorting the array, I 
scan it once while tracking the three largest and two smallest
values. After the traversal, I compute both candidate products
and return the larger one. This reduces the time complexity 
from O(n log n) to O(n) while using constant extra space."
*/

class Solution {
public:
    int maximumProduct(vector<int>& nums) {

        int max1 = INT_MIN;
        int max2 = INT_MIN;
        int max3 = INT_MIN;

        int min1 = INT_MAX;
        int min2 = INT_MAX;

        for (int num : nums) {

            if (num > max1) {
                max3 = max2;
                max2 = max1;
                max1 = num;
            }
            else if (num > max2) {
                max3 = max2;
                max2 = num;
            }
            else if (num > max3) {
                max3 = num;
            }

            if (num < min1) {
                min2 = min1;
                min1 = num;
            }
            else if (num < min2) {
                min2 = num;
            }
        }
     return max(max1 * max2 * max3, min1 * min2 * max1);
    }
};