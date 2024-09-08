// 1143. Longest Common Subsequence
// runtime : 11 ms Beats 98.88%
// space : 7.80 MB Beats 99.45%

// https://www.youtube.com/watch?v=rHV2MT2tD7Y&t=722s 教學影片

// c(i,j) is the length of the LCS of Xi Yj

//         1. 0                           (if i=0 or j=0)
// c(i,j)= 2. c[i-1][j-1]+1               (if i,j>0 and Xi = Yj)   // 加 1 是 Xi = Yj，算一個相等
//         3. max(c[i-1][j],c[i][j-1])    (if i,j>0 and Xi != Yj)

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size(),n=text2.size();
        vector<int> dp(n+1,0); // 為了處理邊界條件
        for(int i=1;i<=m;i++){
            int pre=0; // 相當於 dp[i-1][j-1]
            for(int j=1;j<=n;j++){
                int temp=dp[j]; // 暫存當前的 dp[j],它將成為下一個迭代的 dp[i-1][j-1]
                if(text1[i-1]==text2[j-1]){
                    dp[j]=pre+1;
                }
                else{
                    dp[j]=max(dp[j],dp[j-1]);
                }
                pre=temp; // 為下一次迭代更新 pre
            }
        }
        return dp[n];
    }
};