/*
We define a harmonious array is an array where the difference between its maximum value and its minimum value is exactly 1.

Now, given an integer array, you need to find the length of its longest harmonious subsequence among all its possible subsequences.

Example 1:
Input: [1,3,2,2,5,2,3,7]
Output: 5
Explanation: The longest harmonious subsequence is [3,2,2,2,3].
Note: The length of the input array will not exceed 20,000.
*/



class Solution {
public:
    int findLHS(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> count;
        for (int x:nums) count[x]++;
        for (auto x:count) {
            int key = x.first, value = x.second;
            if (count.find(key+1) != count.end()) // why cannot use count[key+1] > 0? test case [1,2,3,4]
                res = max(res, count[key] + count[key+1]);
        }
        return res;
    }
};

// time    O(n)
// space   O(n)
        