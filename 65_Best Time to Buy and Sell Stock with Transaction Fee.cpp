// 714. Best Time to Buy and Sell Stock with Transaction Fee
// runtime : 69 ms Beats 89.30%
// space : 57.42 MB Beats 97.65%

// 遍歷每一天的股價 price:
// 	•	buy = max(buy, sell - price);
// 	•	這行的意思是，當天選擇是否應該買入股票。我們有兩種選擇：
// 	    1.	保持目前的狀態，即之前已經買入，保持不變，因此收益是 buy。
// 	    2.	或者我們選擇在今天買入股票，此時我們需要支付當前的股價 price，因此我們剩下的收益是 sell - price。

// 	•	sell = max(sell, buy + price - fee);
// 	•	這行的意思是，當天選擇是否應該賣出股票。賣出後我們需要支付交易費用 fee，因此我們有兩種選擇：
// 	    1.	保持目前的狀態，即之前賣出並且不再持有股票，收益是 sell。
// 	    2.	或者我們選擇在今天賣出股票，賣出的收益是 buy + price - fee。

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int buy=INT_MIN; // 表示在某一天持有股票後的最大可能收益，初始階段沒有股票，所以讓第一次一定會買股票
        int sell=0; // 表示在某一天不持有股票後的最大可能收益，一開始沒有進行任何交易時，所以初始收益為 0
        for(int price:prices){
            buy=max(buy,sell-price);
            sell=max(sell,buy+price-fee);
        }
        return sell;
    }
};