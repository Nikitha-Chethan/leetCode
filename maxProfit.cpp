#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
    int maxProfit(vector<int>& prices)
    {
        int maxProfit = 0, bestBuy = prices[0];
        for(int i = 1; i < prices.size(); i++)
        {
            // If current price is greater than bestBuy, calculate profit
            if(prices[i] > bestBuy)
            {
                maxProfit = max(maxProfit, prices[i] - bestBuy); // Calculate profit if sold at current price
            }
            bestBuy = min(bestBuy, prices[i]); // Ensure bestBuy is always the lowest price seen so far
        }
        return maxProfit; // Return the maximum profit found
    }
};
int main()
{
    Solution sol;
    vector<int> prices = {7,1,5,3,6,4};
    int result = sol.maxProfit(prices);
    cout << "Maximum profit: " << result << endl;
    
    return 0;
}