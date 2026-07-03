/*
Problem: 42. Trapping Rain Water
Difficulty: Hard

Topic:
- Arrays
- Two Pointers

Pattern:
- Two Pointer Technique
- Prefix Maximum / Suffix Maximum Optimization

Problem Statement:
Given an elevation map represented by an integer array
'height', where the width of each bar is 1, compute the
total amount of rainwater that can be trapped after
raining.

Approach:
- Initialize two pointers:
    - l at the beginning of the array.
    - r at the end of the array.
- Maintain:
    - lmax: Highest bar encountered from the left.
    - rmax: Highest bar encountered from the right.
- At each step:
    - Update lmax and rmax.
    - If lmax < rmax:
        - The left side limits the trapped water.
        - Water trapped at index l is:
              lmax - height[l]
        - Move the left pointer forward.
    - Otherwise:
        - The right side limits the trapped water.
        - Water trapped at index r is:
              rmax - height[r]
        - Move the right pointer backward.
- Continue until both pointers meet.

Why It Works:
The amount of water above a bar depends on the shorter of
the tallest bars on its left and right.

When lmax < rmax:
- The left side is the limiting boundary.
- Since a taller boundary already exists on the right,
  the trapped water at the current left index depends
  only on lmax.
- Therefore, it is safe to compute the trapped water and
  move the left pointer.

Similarly, when rmax <= lmax:
- The right side becomes the limiting boundary.
- Water at the current right index depends only on rmax.

This eliminates the need for separate prefix and suffix
arrays while still computing the correct result.

Time Complexity:
O(n) - Each pointer traverses the array at most once.

Space Complexity:
O(1) - Only a few extra variables are used.

Explanation :
"The water trapped at any index depends on the minimum 
of the tallest bar to its left and the tallest bar to
its right. A straightforward optimization is to precompute
left and right maximum arrays, but that requires O(n) extra
space. In this solution, I maintain two pointers along with
lmax and rmax. If lmax is smaller than rmax, then the left
side is the limiting boundary, so the water at the current 
left index depends only on lmax. I compute it and move the
left pointer. Otherwise, I do the same for the right side.
This allows me to compute the answer in one pass using O(1) extra space."
*/

class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();

        int ans = 0;
        int lmax = 0, rmax = 0;
        int l = 0, r = n - 1; // two pointers left and right 

        while (l < r) {

            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);

            if (lmax < rmax) {
                ans += lmax - height[l];
                l++;
            } else {
                ans += rmax - height[r];
                r--;
            }
        }
         return ans;
    }
};