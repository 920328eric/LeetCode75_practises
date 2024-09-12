// 1268. Search Suggestions System
// runtime : 830 ms Beats 5.96%
// space : 335.80 MB Beats 19.17%

// string.substr( 子字符串的起始位置（可選，默認為 0）, 子字符串的長度（可選，默認為到字符串結尾）)

// 用 Trie 表現會最好，可自行嘗試
// 1.先架好 TrieNode 結構，裡頭包含 insert、search
// 2.主函數先把所有 products insert 到 TrieNode 裡
// 3.接著就可以在主函數裡，找到對應 prefix 的答案了

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        vector<vector<string>> ans;
        string prefix;
        for(char c:searchWord){
            prefix+=c;
            vector<string> matches;
            for(string s:products){
                if(s.substr(0,prefix.size())==prefix){
                    matches.push_back(s);
                    if(matches.size()==3){
                        break;
                    }
                }
            }
            ans.push_back(matches);
        }
        return ans;
        
    }
};