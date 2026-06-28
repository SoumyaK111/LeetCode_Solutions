/*

Problem: 169. Majority_Element
Difficulty: Easy

Topic:
- Arrays


Pattern:
- Moore's Voting Algorithm

Problem Statement:
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋
times. You may assume that the majority element always exists in the array.

Approach:
Maintain a candidate variable to store the potential majority element and
a freq (count) variable.
Iterate through the array:
If freq is 0, assign the current element as the new candidate.
If the current element is equal to the candidate, increment freq.
Otherwise, decrement freq.
Because the majority element appears more than ⌊n / 2⌋ times, it is guaranteed to
remain as the candidate by the end of the traversal.

Why It Works:
The algorithm relies on the property that the majority element appears more
than all other elements combined. Every time we encounter a different element,
we "cancel out" one instance of our candidate. Since the majority element has
a count greater than the sum of all other elements, it will be the last one standing.

Time Complexity:
O(n) - We perform a single linear scan through the array.

Space Complexity:
O(1) - We use only two integer variables regardless of the input size.
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int freq =0 , ans =0;

        for(int i=0;i<nums.size();i++)
        {
            if(freq==0)
            {
                ans = nums[i];
            }
            if(ans == nums[i])
            {
                freq++;
            }
            else{
                freq--;
            }
        }
        return ans ;
    }
};