/*
Problem: 121. Best Time to Buy and Sell Stock
Difficulty: Easy

Topic:
- Arrays

Pattern:
- Single Pass
- Greedy

Problem Statement:
Given an array where prices[i] represents the stock price
on the ith day, determine the maximum profit that can be
earned by buying one stock and selling it later. If no
profit is possible, return 0.

Approach:
- Initialize:
    - bestBuy as the price on the first day.
    - maxProfit as 0.
- Traverse the array starting from the second day.
- If the current price is greater than bestBuy,
  calculate the profit and update maxProfit if needed.
- Update bestBuy whenever a lower stock price is found.
- Return the maximum profit after processing all days.

Why It Works:
To maximize profit, the stock should be bought at the
lowest price seen so far and sold at a higher price later.
Keeping track of the minimum price while scanning the array
allows us to compute the best possible profit in a single
pass.

Time Complexity:
O(n) - The array is traversed exactly once.

Space Complexity:
O(1) - Only two extra variables are used.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0, bestBuy = prices[0];

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > bestBuy) {
                maxProfit = max(maxProfit, prices[i] - bestBuy);
            }
            bestBuy = min(bestBuy, prices[i]);
        }
        return maxProfit;
    }
};