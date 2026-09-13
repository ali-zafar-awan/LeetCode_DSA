class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int b = prices[0], s = b, p=0;

        for(int i= 1;i<prices.size();i++){
            if(prices[i]<b){
                b=s=prices[i];
            }else if(prices[i]>s){
                s=prices[i];
            }
            if((s-b)>p){
                    p=s-b;
                }
        }
        return p;
    }
};