// problem link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock
// time complexity - O(N)
// space complexity - O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n=prices.size();
        if(!n)
            return 0;
     int mi=INT_MAX,max_profit=0;
        for(int i=0;i<n;i++){
            mi=min(mi,prices[i]);
            max_profit=max(max_profit,prices[i]-mi);
        }
        return max_profit;


    }
};
