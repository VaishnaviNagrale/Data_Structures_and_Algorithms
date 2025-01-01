class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        //Optimal Approch - TC:O(n),SC:O(1)
        int mini = prices[0],profit=0;
        for(int i=1;i<prices.size();i++){
            int profit_cost = prices[i] - mini;
            profit = max(profit,profit_cost);
            mini = min(mini,prices[i]);
        }
        return profit;

        // int n=prices.size();
        // int profit=0;
        // int i=0,j=1;
        // while(i<n && j<n){
        //     if(prices[i]>=prices[j]){
        //         i=j;
        //     }
        //     else{
        //         profit=max(profit,prices[j]-prices[i]);
        //     }
        //     j++;
        // }
        // return profit;


        // int mini=INT_MAX;
        // int p1;
        // for(int i=0;i<n;i++){
        //     if(prices[i]<mini){
        //         mini=prices[i];
        //         p1=i;
        //     }
        // }
        // if(p1==n-1){
        //     return 0;
        // }
        // int maxi=INT_MIN;
        // for(int i=p1;i<n;i++){
        //     maxi=max(maxi,prices[i]);
        // }
        // return maxi-mini; 
        
    }
};