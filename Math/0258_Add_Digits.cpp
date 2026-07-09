/*
Problem: 258. Add Digits
Difficulty: Easy

Topic:
- Math

Pattern:
- Mathematical Observation
- Digital Root

Problem Statement:
Given a non-negative integer num, repeatedly add its digits
until the result contains only one digit.

Return the final single-digit number.

Approach:
- Observe that repeatedly summing the digits of a number
  always produces its Digital Root.
- The Digital Root follows a simple mathematical formula:
    - If num == 0:
        return 0
    - Otherwise:
        return 1 + (num - 1) % 9
- This eliminates the need to repeatedly process the digits.

Why It Works:
Every positive integer has a unique Digital Root.

The pattern follows modulo 9 arithmetic:

1 → 1
2 → 2
...
9 → 9
10 → 1
11 → 2
...
18 → 9
19 → 1

Instead of repeatedly summing digits, the formula computes
the final result directly in constant time.

Time Complexity:
O(1) - Only a few arithmetic operations are performed.

Space Complexity:
O(1) - Uses constant extra space.

Explanation :
"A straightforward approach is to repeatedly extract and sum 
the digits until only one digit remains. However, this process 
always converges to the number's digital root, which follows a 
mathematical pattern based on modulo 9. For any positive number, 
the digital root is 1 + (num - 1) % 9, while 0 is a special case. 
Using this observation, I can compute the answer directly in constant 
time without iterating through the digits."
*/

class Solution {
public:
    int addDigits(int num) {

        // Digital Root Formula
        if (num == 0) {
            return 0;
        }

        return 1 + (num - 1) % 9;
    }
};