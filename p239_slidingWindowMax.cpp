// Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.

// Example:

// Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
// Output: [3,3,5,5,6,7] 
// Explanation: 

// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
// Note: 
// You may assume k is always valid, 1 ≤ k ≤ input array's size for non-empty array.

// Follow up:
// Could you solve it in linear time?


// O(n) time, each index get in and out mostly once
// O(k) space
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> d;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            while (!d.empty() && nums[d.back()] < nums[i])
                d.pop_back();
            d.push_back(i);
            if (d[0] == i - k)
                d.pop_front();
            if (i >= k - 1)
                res.push_back(nums[d[0]]);
        }
        return res;
    }
};

        