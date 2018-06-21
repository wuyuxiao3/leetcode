// Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

// Example 1:
// Input:nums = [1,1,1], k = 2
// Output: 2
// Note:
// The length of the array is in range [1, 20,000].
// The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].


// O(n) time
// O(n) space, worst case
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> cnt = {{0, 1}};
        int res = 0, cursum = 0;
        for (int x: nums) {
            cursum += x;
            res += cnt[cursum - k]; // if cursum - k not exist, will get default = 0
            cnt[cursum]++;
        }
        return res;
    }
};
/*
        suppose running sum 0:j = cursum
        then sum of i:j = k if some running sum 0:i-1 = cursum - k exists for (multiple) i
        0_____i_____j_____
*/