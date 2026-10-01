class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r = 1;
        int large = 0;
        while(r < prices.size())
        {
            
            if(prices[l]< prices[r])
            {
                int sum = prices[r]-prices[l];
                large = max(sum,large);
            }
            else 
            {
                l=r;

            }
            r++;
            
        }
        return large;
    }
};
