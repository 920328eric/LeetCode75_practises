// 790. Domino and Tromino Tiling
// runtime : 0 ms Beats 100.00%
// space : 7.87 MB Beats 50.87%

// dp[0]=1，雖然一個 2 * 0 是空的，但假設有 1 種鋪法，不然無法推出公式

// formula : dp[n] = 2 * dp[n-1] + dp[n-3]

// 1e9 = 1 * 10^9
// 9e8 = 9 * 10^8

class Solution {
public:
    int numTilings(int n) {
        int mod=1e9+7; // 題目要求
        long long dp[1001]; // 1 <= n <= 1000
        dp[0]=1; // 雖然一個 2 * 0 是空的，但假設有 1 種鋪法，不然無法推出公式
        dp[1]=1;
        dp[2]=2;
        dp[3]=5;
        for(int i=4;i<=n;i++){
            dp[i]=(2*dp[i-1]+dp[i-3]) % mod;
        }
        return dp[n] % mod;
    }
};