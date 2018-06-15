// Say you have an array for which the ith element is the price of a given stock on day i.

// Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

// You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
// After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
// Example:

// Input: [1,2,3,0,2]
// Output: 3 
// Explanation: transactions = [buy, sell, cooldown, buy, sell]

	

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int buy = -prices[0], sell = 0, presell = 0;
        for (int p: prices) {
            int prebuy = buy;
            buy = max(buy, presell - p);
            presell = sell;
            sell = max(sell, prebuy + p);
        }
        return sell;
    }
};
//      0   1   2   i-2     i-1     i
// buy                      buy     new buy
// sell             presell sell    new sell

// buy[i] = max(buy[i-1],sell[i-2]-curr_price)
// sell[i] = max(sell[i-1],buy[i-1]+curr_price)


// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         if (n < 2) return 0;
//         int rest[n] = {0}, buy[n] = {-prices[0]}, sell[n] = {0};
//         for (int i = 1; i < n; i++) {
//             rest[i] = max(rest[i-1], sell[i-1]);
//             buy[i] = max(buy[i-1], rest[i-1] - prices[i]);
//             sell[i] = buy[i-1] + prices[i];
//         }
//         return max(rest[n-1], sell[n-1]);
//     }
// };