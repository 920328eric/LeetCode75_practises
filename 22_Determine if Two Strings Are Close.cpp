// 1657. Determine if Two Strings Are Close
// runtime：98 ms
// space : 23.42 MB 

// key1:字符集必須相同：兩個字符串如果要相互變換，那麼它們包含的字符必須完全一樣。
// key2:字符頻率必須相同：每個字符出現的次數也必須一致，因為交換操作不會改變字符的出現次數。(頻率出現的頻率相同就好)
//      => 舉個例子：
// 	        •	word1 = "aabbcc"
//      	•	word2 = "ccbbaa"
//         兩個字符串的 freq1 和 freq2 結果都是：
//      	•	a 出現 2 次
//      	•	b 出現 2 次
//      	•	c 出現 2 次
//         因此，freqCount1 和 freqCount2 都會統計到出現 2 次的頻率為 3，即：
//      	•	2 出現 3 次
//         這樣，我們在比較 freqCount1 和 freqCount2 時，它們的結果是相同的。

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size()){
            return false;
        }
        unordered_map<char,int> freq1,freq2;
        for(char c : word1){
            freq1[c]++;
        }
        for(char c : word2){
            freq2[c]++;
        }
        for(const auto& pair:freq1){ 
            if(freq2.find(pair.first)==freq2.end()){ // 字符集必須相同
                return false;
            }
        }
        unordered_map<int,int> freqcou1,freqcou2; // 字符頻率的頻率必須相同
        for(const auto& pair : freq1){
            freqcou1[pair.second]++;
        }
        for(const auto& pair : freq2){
            freqcou2[pair.second]++;
        }
        return freqcou1 == freqcou2; // unordered_map 本質上是一個無序的數據結構，只要 freqcou1 和 freqcou2 包含相同的鍵值對，它們就會被認為是相等的
    }
};