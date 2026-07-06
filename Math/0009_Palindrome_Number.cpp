/*
Problem: 9. Palindrome Number
Difficulty: Easy

Topic:
- Math

Pattern:
- Reverse Half of Number

Problem Statement:
Given an integer x, return true if x is a palindrome,
and false otherwise.

A palindrome reads the same forward and backward.

Approach:
- Handle special cases:
    - Negative numbers are never palindromes.
    - Numbers ending with 0 (except 0 itself) cannot be
      palindromes.
- Reverse only the second half of the number.
- Stop when the reversed half becomes greater than or
  equal to the remaining half.
- Compare:
    - Even number of digits:
        x == reversedHalf
    - Odd number of digits:
        x == reversedHalf / 10
      (Ignore the middle digit.)

Why It Works:
A palindrome has identical first and second halves.

Instead of reversing the entire number, reverse only half
of it. This avoids integer overflow and performs fewer
operations.

For odd-length numbers, the middle digit does not affect
whether the number is a palindrome, so it is discarded by
dividing reversedHalf by 10.

Time Complexity:
O(log10 n) - Processes approximately half of the digits.

Space Complexity:
O(1) - Uses only a few integer variables.

Explanation :
"I first handle edge cases: negative numbers and positive
numbers ending in zero, except zero itself, cannot be palindromes.
Instead of reversing the entire number, I reverse only the second
half. Once the reversed half becomes greater than or equal to the 
remaining half, I stop. For even-digit numbers, the two halves should
be equal. For odd-digit numbers, I ignore the middle digit by dividing
the reversed half by 10 before comparison. This approach avoids integer
overflow and uses constant extra space."
*/

class Solution {
public:
    bool isPalindrome(int x) {

        // Negative numbers are not palindromes.
        // Numbers ending with 0 (except 0 itself) can't be palindromes.
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;

        int reversedHalf = 0;

        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }

        // Even digits: x == reversedHalf
        // Odd digits: x == reversedHalf / 10
        return x == reversedHalf || x == reversedHalf / 10;
    }
};