/*
Problem: 2520. Count the Digits That Divide a Number
Difficulty: Easy

Topic:
- Math

Pattern:
- Digit Manipulation

Problem Statement:
Given an integer num, return the number of digits in num
that evenly divide the original number.

A digit divides num if:
    num % digit == 0

It is guaranteed that num does not contain the digit 0.

Approach:
- Store the original number in a separate variable.
- Traverse each digit of the number:
    - Extract the last digit using % 10.
    - Check whether the original number is divisible by
      the extracted digit.
    - If yes, increment the count.
    - Remove the processed digit using / 10.
- Return the total count.

Why It Works:
Each digit is examined exactly once.

The original number is preserved because we continuously
modify num while extracting its digits.

Whenever:
    originalNum % digit == 0

the digit contributes to the answer.

Time Complexity:
O(n) - n is the number of digits.

Space Complexity:
O(1) - Uses only a few integer variables.

Explanation : 
"I preserve the original number because I need it for every 
divisibility check. Then I process the number digit by digit 
using % 10 to extract the last digit and / 10 to remove it. 
For each extracted digit, I check whether the original number 
is divisible by that digit. If it is, I increment the count. 
Since each digit is processed exactly once, the solution runs 
in O(n) time with constant extra space."
*/

class Solution {
public:
    int countDigits(int num) {

        int originalNum = num;
        int count = 0;

        while (num > 0) {

            int digit = num % 10;

            if (originalNum % digit == 0) {
                count++;
            }

            num /= 10;
        }

        return count;
    }
};