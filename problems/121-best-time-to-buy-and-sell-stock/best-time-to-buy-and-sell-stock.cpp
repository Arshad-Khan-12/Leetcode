class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Initialize the minimum price with the first day's price.
        int minPrice = prices[0];
        // Initialize the maximum profit to 0.
        int maxProfitValue = 0;

        // Iterate through the stock prices starting from day 1.
        for (int i = 1; i < prices.size(); i++) {
            // Update the minimum price encountered so far.
            minPrice = min(minPrice, prices[i]);
            // Calculate the profit if selling on the current day.
            int profitToday = prices[i] - minPrice;
            // Update the maximum profit if today's profit is higher.
            maxProfitValue = max(maxProfitValue, profitToday);
        }

        // Return the maximum profit found.
        return maxProfitValue;
    }
};
