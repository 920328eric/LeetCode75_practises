// 1137. N-th Tribonacci Number
// runtime : 0 ms Beats 100.00%
// space : 7.46 MB Beats 52.41%

// O(n) time and O(1) space

class Solution {
public:
    int tribonacci(int n) {
        int dp[3]={0,1,1}; // 只紀錄最近三筆的資料
        for(int i=3;i<=n;i++){ // 從 n >= 3 開始更新
            dp[i%3]=dp[0]+dp[1]+dp[2]; // 依序更新最近三筆的資料
        }
        return dp[n%3];
    }
};