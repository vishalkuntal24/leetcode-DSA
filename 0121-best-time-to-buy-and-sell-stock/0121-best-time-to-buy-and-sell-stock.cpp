class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int profit=0 ;
        int left_min = prices[0] ;

        for ( int i=1 ; i<prices.size() ; i++)
        {
            int x = prices[i]-left_min ;

            profit=max(profit,x) ;
            left_min=min(left_min,prices[i]) ;
        }

        return profit ;
        
    }
};