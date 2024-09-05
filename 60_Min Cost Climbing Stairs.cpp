// 746. Min Cost Climbing Stairs
// runtime : 0 ms Beats 100.00%
// space : 16.67 MB Beats 67.49%

// 看不懂可以自行畫圖追蹤，就會很明顯

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        for(int i=2;i<n;i++){ // 只有兩個數直接比哪個值較小，因為兩個數都能直接到 top
            cost[i]+=min(cost[i-1],cost[i-2]); // 比如說三個數，可以到達 top 的，有最後兩個數，所以要先更改這兩個 cost，也就是各加上前兩個取min
        }
        return min(cost[n-1],cost[n-2]); // 大於兩個數比最後兩個數哪個值比較小，因為兩個數都能直接到 top，各 cost 數值都已改成各個最小花費的 cost
    }
};