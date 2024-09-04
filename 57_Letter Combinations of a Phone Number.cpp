// 17. Letter Combinations of a Phone Number
// runtime : 0 ms Beats 100.00%
// space : 10.20 MB Beats 7.14%

// Backtracking:
//  用於解決組合問題、排列問題、子集問題，
//  主要用於找到所有可能的解，並通過撤銷選擇來進行探索。它更注重於在某些選擇無法解決問題時，撤銷這些選擇並嘗試其他選擇。
// DFS:
//  主要用於圖或樹的遍歷，並尋找從一個節點到其他節點的路徑。DFS 本身不一定涉及撤銷選擇，而是繼續探索所有可能的路徑。

// string str = "abc";
// str.push_back('d'); // str 現在是 "abcd"

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<int,vector<char>> smap;
        smap[2] = {'a', 'b', 'c'};
        smap[3] = {'d', 'e', 'f'};
        smap[4] = {'g', 'h', 'i'};
        smap[5] = {'j', 'k', 'l'};
        smap[6] = {'m', 'n', 'o'};
        smap[7] = {'p', 'q', 'r', 's'};
        smap[8] = {'t', 'u', 'v'};
        smap[9] = {'w', 'x', 'y', 'z'};
        vector<string> ans;
        string str=""; // 存放所有可能的答案，加到 ans 
        if(digits.size()>0){
            backtrack(ans,smap,digits,str,0);
        }
        return ans;
    }
    void backtrack(vector<string>& ans,unordered_map<int,vector<char>> smap,string digits,string& str,int dig){
        if(dig==digits.size()){ // 結束遞迴的條件，就是找到其中一種可能的答案，加進 ans 裡
            ans.push_back(str);
            return;
        }
        int num=digits[dig]-'0'; // 因為題目給的是 string，所以要扣掉 ASCII 的 '0'=50
        for(int i=0;i<smap[num].size();i++){
            str.push_back(smap[num][i]);
            backtrack(ans,smap,digits,str,dig+1);
            str.pop_back(); // 為了 Backtrack，所以 pop 掉 str 最後一個字母
        }
    }
};