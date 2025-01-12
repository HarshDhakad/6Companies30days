class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        int limits=2*k;
        vector<int>prev(limits+1,0);
        vector<int>curr(limits+1,0);
        for(int index=n-1;index>=0;index--){
            for(int limit=limits-1;limit>=0;limit--){
                if(limit%2==0){
                    curr[limit]=max(-prices[index]+prev[limit+1],
                    prev[limit]);
                }
                else{
                    curr[limit]=max(prices[index]+prev[limit+1],
                    prev[limit]);
                }
            }
            prev=curr;
        }
        return prev[0];
    }
};
