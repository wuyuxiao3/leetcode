// Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn't one, return 0 instead.

// Note:
// The sum of the entire nums array is guaranteed to fit within the 32-bit signed integer range.

// Example 1:

// Input: nums = [1, -1, 5, -2, 3], k = 3
// Output: 4 
// Explanation: The subarray [1, -1, 5, -2] sums to 3 and is the longest.
// Example 2:

// Input: nums = [-2, -1, 2, 1], k = 1
// Output: 2 
// Explanation: The subarray [-1, 2] sums to 1 and is the longest.
// Follow Up:
// Can you do it in O(n) time?


// O(n) time
// O(n) space, worst case
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> hash = {{0, -1}}; // key: sum of nums[:idx] (including idx), value: idx
        int res = 0, cursum = 0;
        for (int i = 0; i < nums.size(); i++) {
            cursum += nums[i];
            if (hash.find(cursum - k) != hash.end())
                res = max(res, i - hash[cursum - k]);
            if (hash.find(cursum) == hash.end())
                hash[cursum] = i;
        }
        return res;
    }
};
/*
        suppose running sum 0:j = cursum
        then sum of i+1:j = k if some running sum 0:i = cursum - k exists for (multiple) i
        0_____i_____j_____    
*/