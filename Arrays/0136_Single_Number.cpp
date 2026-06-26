/*
Problem: 136. Single Number
Difficulty: Easy

Topic:
- Arrays
- Bit Manipulation

Pattern:
- XOR

Problem Statement:
Given a non-empty integer array where every element appears
exactly twice except for one element, return the element
that appears only once.

Approach:
- Initialize a variable 'ans' to 0.
- Traverse the array and perform the XOR operation with each
  element.
- Since XOR of two identical numbers is 0, all duplicate
  elements cancel each other out.
- The remaining value is the unique element.

Why It Works:
XOR has the following properties:
- a ^ a = 0
- a ^ 0 = a
- XOR is commutative and associative.

As every duplicate pair cancels out, only the element that
appears once remains.

Time Complexity:
O(n) - Traverse the array once.

Space Complexity:
O(1) - Uses only one extra integer variable.
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;

        for (int val : nums) {
            ans ^= val;
        }

        return ans;
    }
};

