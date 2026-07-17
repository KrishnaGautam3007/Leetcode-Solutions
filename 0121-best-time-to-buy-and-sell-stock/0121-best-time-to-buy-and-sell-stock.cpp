class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int buy=prices[0];
       int maxprofit=0;
       for(int i=1;i<prices.size();i++){
            maxprofit=max(maxprofit,prices[i]-buy);
            buy=min(prices[i],buy);
        }
        return maxprofit;
    }
};
