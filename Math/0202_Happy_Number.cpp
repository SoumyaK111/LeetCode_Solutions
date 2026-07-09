/*
Problem: 202. Happy Number
Difficulty: Easy

Topic:
- Math
- Hash Table

Pattern:
- Floyd's Cycle Detection (Tortoise and Hare)
- Digit Manipulation

Problem Statement:
A happy number is defined by repeatedly replacing a number
with the sum of the squares of its digits.

If this process eventually reaches 1, the number is happy.
Otherwise, it enters a cycle and is not happy.

Return true if n is a happy number, otherwise false.

Approach:
- Create a helper function getNext() to compute the sum of
  the squares of the digits.
- Use Floyd's Cycle Detection algorithm:
    - slow moves one transformation at a time.
    - fast moves two transformations at a time.
- If slow and fast meet:
    - If they meet at 1, the number is happy.
    - Otherwise, a cycle exists and the number is not happy.

Why It Works:
Every number generates a sequence after repeatedly applying
the digit-square transformation.

This sequence has only two possibilities:
1. It reaches 1 and stays there.
2. It enters a repeating cycle.

Floyd's algorithm efficiently detects cycles without using
extra memory.

Time Complexity:
O(log n)
- Each transformation processes all digits of the number.
- The sequence reaches a cycle after a bounded number of
  transformations.

Space Complexity:
O(1) - Uses only a few integer variables.

Explanation :
"Each application of the digit-square operation produces the 
next value in a sequence. A sequence can either eventually reach 
1 or enter a repeating cycle. Instead of storing visited numbers 
in a HashSet, I use Floyd's Cycle Detection algorithm. I maintain 
two pointers: slow advances one transformation at a time, while fast 
advances two. If they meet at 1, the number is happy. If they meet 
at any other value, a cycle exists, so the number is not happy. 
This achieves constant extra space."
*/

class Solution {
public:
    int getNext(int n) {

        int sum = 0;

        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }

        return sum;
    }

    bool isHappy(int n) {
        // using floyd's detection algorithm

        int slow = n;
        int fast = n;

        do {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }
        while (slow != fast);

        return slow == 1;
    }
};