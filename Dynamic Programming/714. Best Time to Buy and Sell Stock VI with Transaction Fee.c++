class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
         int n = prices.size();
        vector<int> prev(2,0),curr(2,0);
        prev[0]=0;
        prev[1]=0;
        int profit = 0;
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                if(buy){
                    int buyid = -prices[i] + prev[0];
                    int notbuyid = prev[1];
                    profit = max(buyid,notbuyid);
                }else{
                    int sell = prices[i] - fee + prev[1];
                    int notsell = prev[0];
                    profit = max(sell,notsell);
                }
                curr[buy] = profit;
            }
            prev = curr;
        }
        return prev[1];
    }
};