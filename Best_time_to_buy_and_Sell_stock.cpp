// leetcode
// code in c++
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // Agar array ka size 0 hai toh profit 0 hoga
        if (prices.size() == 0)
            return 0;
        int profit = 0;
        int low = prices[0], high = prices[0]; // hum phela element hi max maan lenge aur usse buying price bhi
        for (int i = 0; i < prices.size(); i++)
        {
            // yaha hum buy karne ki prices find karenge agar vo first element nhi hai
            if (prices[i] < low)
            {
                // yaha hum profit calculate karenge update se phle
                profit = max(profit, high - low);
                low = prices[i];
                high = prices[i];
            }
            else
            {
                // agar element low se bada h toh hum high k liye check karenge
                high = max(high, prices[i]);
            }
        }
        // yaha hum final profit calculate karenge answer k liye
        profit = max(profit, high - low);
        return profit;
    }
};

// Code in java
class Solution
{
public
    int maxProfit(int[] prices)
    {
        // Base case...
        // If the array is empty or its length <= 1, return 0...
        if (prices == null || prices.length <= 1)
            return 0;
        // Initialize the minimum price to buy...
        int minBuy = prices[0];
        // Initialize the maximum profit...
        int profit = 0;
        // Traverse all elements through a for loop...
        for (int i = 1; i < prices.length; i++)
        {
            // Get the minimum price to buy...
            minBuy = Math.min(minBuy, prices[i]);
            // Get maximum profit...
            profit = Math.max(profit, prices[i] - minBuy);
        }
        return profit; // return the maximum profit...
    }
}