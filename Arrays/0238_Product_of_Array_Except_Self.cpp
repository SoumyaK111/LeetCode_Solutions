/*
Problem: 238. Product of Array Except Self
Difficulty: Medium

Topic:
- Arrays

Pattern:
- Prefix Product
- Suffix Product
- Precomputation

Problem Statement:
Given an integer array nums, return an array ans such
that ans[i] is equal to the product of all elements
of nums except nums[i].

The solution must run in O(n) time without using the
division operator.

Approach:
- Create an answer array initialized with 1.
- First pass (Prefix Product):
    - Store the product of all elements to the left of
      each index.
- Second pass (Suffix Product):
    - Maintain a running suffix product.
    - Multiply the stored prefix product with the suffix
      product to obtain the final answer.

Why It Works:
For every index i,

answer[i] = (Product of all elements before i)
          × (Product of all elements after i)

Instead of computing these products separately for every
index, we precompute prefix products and calculate suffix
products on the fly in a second traversal.

This avoids division and achieves linear time.

Time Complexity:
O(n)
- One pass for prefix products.
- One pass for suffix products.

Space Complexity:
O(1) Extra Space
- Ignoring the output array as per the problem statement.
- Only one additional variable (suffix) is used.

Explanation :
"The brute-force solution computes the product for every
index separately, resulting in O(n²) time. To optimize, 
I observe that the answer at each index is the product of
all elements to its left multiplied by the product of all
elements to its right. I first store prefix products in
the output array. Then I traverse from right to left 
while maintaining a running suffix product and multiply 
it with the corresponding prefix product. This avoids 
using division, runs in O(n) time, and uses only O(1) 
extra space besides the output array."
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();
        vector<int> ans(n, 1);

        // Prefix Product
        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        // Suffix Product
        int suffix = 1;

        for (int i = n - 2; i >= 0; i--) {
            suffix *= nums[i + 1];
            ans[i] *= suffix;
        }

        return ans;
    }
};
