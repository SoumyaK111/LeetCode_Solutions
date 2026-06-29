/*

Problem: 50. Pow(x, n)
Difficulty: Medium

Topic:
- Math
- Recursion
- Binary Search

Pattern:
- Binary Exponentiation (Exponentiation by Squaring)

Problem Statement:
Implement pow(x, n), which calculates x raised to the
power n (xⁿ).

Approach:
- Handle special edge cases such as:
    - n == 0
    - x == 0
    - x == 1
    - x == -1
- Convert the exponent to a long to safely handle the
  minimum integer value (INT_MIN).
- If the exponent is negative:
    - Replace x with its reciprocal (1/x).
    - Convert the exponent to its positive equivalent.
- Use Binary Exponentiation:
    - If the current exponent is odd, multiply the answer
      by x.
    - Square x after every iteration.
    - Divide the exponent by 2 until it becomes zero.

Why It Works:
Binary Exponentiation reduces the exponent by half in every
iteration. Instead of multiplying x exactly n times, it
repeatedly squares the base and processes only the set bits
of the exponent, resulting in logarithmic time complexity.

Time Complexity:
O(log n) - The exponent is halved in every iteration.

Space Complexity:
O(1) - Uses only a few additional variables.

*/

class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1.0;
        if(x == 0) return 0.0;
        if(x == 1) return 1.0;
        if(x == -1 && n%2 == 0) return 1.0;
        if (x == -1 && n%2 != 0) return -1.0;

        long binForm = n;
        if(n<0) {
            x = 1/x;
            binForm = -binForm;
        }

        double ans =1;

        while(binForm>0){
            if(binForm %2 == 1)
            {
                ans *= x;

            }
            x *= x;
            binForm /= 2;
        }
        return ans;
    }
};