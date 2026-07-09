/*
Problem: 2119. A Number After a Double Reversal
Difficulty: Easy

Topic:
- Math

Pattern:
- Mathematical Observation
- Digit Manipulation

Problem Statement:
Given a non-negative integer num, reverse it once to obtain
reversed1, then reverse reversed1 to obtain reversed2.

Return true if reversed2 equals the original number,
otherwise return false.

Approach:
- Observe that reversing a number removes any leading zeros.
- Therefore:
    - If the original number ends with one or more zeros,
      those zeros become leading zeros after the first
      reversal and are permanently lost.
- The only exception is the number 0 itself.
- Therefore:
    - Return false if:
        num != 0 && num % 10 == 0
    - Otherwise return true.

Why It Works:
Numbers ending with zero lose those zeros during the first
reversal because leading zeros are not preserved.

Example:
1800
→ 81
→ 18

The second reversal cannot restore the lost zeros.

Numbers that do not end in zero (or are 0) remain unchanged
after two reversals.

Time Complexity:
O(1) - Only a single modulo operation is performed.

Space Complexity:
O(1) - Uses constant extra space.

Explanation :
"Instead of performing two reversals, I use a mathematical observation.
During the first reversal, any trailing zeros become leading zeros, and
leading zeros are discarded. Once they're removed, the second reversal
cannot recover them. Therefore, any non-zero number ending with 0 cannot
remain the same after two reversals. All other numbers, including 0,
do remain the same."
*/

class Solution {
public:
    bool isSameAfterReversals(int num) {

        if (num != 0 && num % 10 == 0) {
            return false;
        }

        return true;
    }
};