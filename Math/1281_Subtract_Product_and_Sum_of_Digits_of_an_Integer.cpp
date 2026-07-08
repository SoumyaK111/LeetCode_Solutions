/*
Problem: 1281. Subtract the Product and Sum of Digits of an Integer
Difficulty: Easy

Topic:
- Math

Pattern:
- Digit Manipulation

Problem Statement:
Given an integer n, calculate:
    - The product of its digits.
    - The sum of its digits.
Return the difference between the product and the sum.

Approach:
- Initialize:
    - product = 1
    - sum = 0
- While n > 0:
    - Extract the last digit using n % 10.
    - Multiply the digit into product.
    - Add the digit to sum.
    - Remove the last digit using n /= 10.
- Return product - sum.

Why It Works:
The modulo operator (%) extracts the last digit of a number,
while integer division (/) removes the last digit.

By processing one digit at a time, every digit contributes
exactly once to both the product and the sum.

Time Complexity:
O(n) - n is the number of digits in n.

Space Complexity:
O(1) - Uses only a few integer variables.

Explanation :
"I process the number one digit at a time using mathematical
operations instead of converting it to a string. In each iteration,
I extract the last digit with % 10, update both the product and the
sum, and then remove the processed digit using integer division by 10.
After all digits are processed, I return the difference between the
product and the sum. This solution runs in O(d) time, where d is the
number of digits, and uses O(1) extra space."
*/

class Solution {
public:
    int subtractProductAndSum(int n) {

        int product = 1;
        int sum = 0;

        while (n > 0) {

            int digit = n % 10;

            product *= digit;
            sum += digit;

            n /= 10;
        }

        return product - sum;
    }
};