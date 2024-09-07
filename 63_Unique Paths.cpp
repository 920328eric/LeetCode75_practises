// 62. Unique Paths
// runtime : 0 ms Beats 100.00%
// space : 7.61 MB Beats 73.94%

// 每行都是更動同一個 vector<int> ans
// 假設 m=4 n=3
//     j=0 j=1 j=2 
// i=0  1   1   1
// i=1  1   2   3
// i=2  1   3   6
// i=3  1   4   10

// ex: i=1 j=1 => i=0 j=0 + i=0 j=1
//     i=1 j=2 => 因為 ans[1] 被 上方式子 i=1 j=1 覆蓋掉了，所以為 ans[1] + i=0 j=2
// 所以每次的計算，自己才會為 前一個數 + 自己的數

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> ans(n,1);
        for(int i=1;i<m;i++){ // i=0 為初始值 1，所以才會從 i=1 開始
            for(int j=1;j<n;j++){ // j=0 為初始值 1，所以才會從 j=1 開始
                ans[j]=ans[j-1]+ans[j]; // 依據上方的舉例解釋
            }
        }
        return ans[n-1]; // c/c++ 陣列從 0 開始
    }
};