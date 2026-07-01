/*
Problem: 11. Container With Most Water
Difficulty: Medium

Topic:
- Arrays
- Two Pointers

Pattern:
- Two Pointer Technique

Problem Statement:
Given an array 'height', where each element represents the
height of a vertical line, find two lines that together
with the x-axis form a container capable of holding the
maximum amount of water.

Approach:
- Initialize two pointers:
    - lp at the beginning of the array.
    - rp at the end of the array.
- Compute:
    - Width = rp - lp
    - Height = min(height[lp], height[rp])
    - Area = Width × Height
- Update the maximum area found.
- Move the pointer pointing to the shorter line inward,
  hoping to find a taller line that may increase the area.
- Continue until the two pointers meet.

Why It Works:
The amount of water is determined by:
    Area = Width × min(leftHeight, rightHeight)

The shorter line always limits the container's height.

Moving the taller line cannot increase the height because
the shorter line still remains the limiting factor, while
the width decreases.

Moving the shorter line is the only possibility to find a
taller line that may compensate for the reduced width and
produce a larger area.

Time Complexity:
O(n) - Each pointer moves at most n times.

Space Complexity:
O(1) - Only constant extra space is used.
*/

class Solution {
public:
    int maxArea(vector<int>& height) {

        int maxWater = 0;
        int lp = 0, rp = height.size() - 1;

        while (lp < rp) {

            int wd = rp - lp;
            int ht = min(height[lp], height[rp]);
            int ar = wd * ht; //currWater in container

            maxWater = max(maxWater, ar);

            height[lp] < height[rp] ? lp++ : rp--;
        }

        return maxWater;
    }
};