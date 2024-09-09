// 72. Edit Distance
// runtime : 0 ms Beats 100.00%
// space : 10.34 MB Beats 94.08%

// if word[i]==word[j] => min(word1[i-1],word2[j-1]);
// else {
//     1. 比較 word1[i] 和 word2[j-1]，因為 word1[i] 後補了一個和 word2[j]相同的的字母   (Insert a character) 
//     2. 比較 word1[i-1] 和 word2[j]，去掉 word1[i]                                 (Delete a character)
//     3. 把 word1[i] 變成和 word2[j] 相同的字母，所以比較 word1[i-1],word2[j-1]        (Replace a character)
//     =>三者取 min + 1
// }

// pre[j-1]：表示將 w1 的前 i-1 個字元轉換成 w2 的前 j-1 個字元所需的編輯距離
// pre[j]：表示將 w1 的前 i-1 個字元轉換成 w2 的前 j 個字元所需的編輯距離。
// cur[j-1]：表示將 w1 的前 i 個字元轉換成 w2 的前 j-1 個字元所需的編輯距離。

// 插入: pre[j]（在 w1 中插入一個字元）
// 刪除: cur[j-1]（從 w1 中刪除一個字元）
// 替換: pre[j-1]（將 w1 中的一個字元替換為 w2 中的字元）
// 我們取這三種操作中的最小值,並加 1 作為當前的編輯距離。

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        vector<int> cur(m+1,0),pre(m+1,0);
        for(int i=0;i<=m;i++){
            pre[i]=i; // 如果其中一個字符串是空字符串，那麼要把它轉換成另一個字符串，我們需要做的操作就是依次插入另一個字符串的每一個字符
        }
        for(int i=1;i<=n;i++){
            cur[0]=i;
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                    cur[j]=pre[j-1]; 
                }
                else{
                    cur[j]=1+min(pre[j-1],min(pre[j],cur[j-1]));
                }
            }
            pre=cur;
        }
        return pre[m];
    }
};