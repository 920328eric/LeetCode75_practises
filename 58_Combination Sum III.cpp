// 216. Combination Sum III
// runtime : 3 ms Beats 49.27%
// space : 8.35 MB Beats 46.17%

class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> cur; // 紀錄目前的數字有哪些
        backtracking(cur,1,k,n); 
        return ans;
    }
    void backtracking(vector<int>& cur,int cnum,int k,int n){
        if(n==0&&cur.size()==k){ // 必須 n-i 到變成 0 且同時滿足 k 個數才可以放入正確答案中
            ans.push_back(cur);
            return;
        }
        for(int i=cnum;i<=9;i++){ // 設從 cnum 開始是為了確保選擇的數字是不重複
            cur.push_back(i);
            backtracking(cur,i+1,k,n-i);
            cur.pop_back(); // 為了 Backtrack，所以 pop 掉 cur 最後一個數
        }
    }
};