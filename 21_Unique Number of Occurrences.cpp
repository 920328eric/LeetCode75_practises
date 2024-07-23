// 1207. Unique Number of Occurrences
// runtime：0 ms
// space : 11.49 MB 

// 1.auto：
// •使用 auto 宣告變數會進行值拷貝。
// •如果你希望對變數進行修改，而這些修改應該反映在原始數據上，那麼 auto 是不適用的，因為它只是一個拷貝。
// 2.auto&：
// •使用 auto& 宣告變數會創建對原始數據的引用。
// •當你需要修改原始數據，或者避免大數據結構的拷貝開銷時，使用引用是必要的。

// occur.insert(pair.second) 返回一個 pair

// •使用 auto 來遍歷 count 時，編譯器會自動確定 pair 的類型是 pair<const int, int>

// •使用 auto 來處理 insert 返回的 pair，result 的類型是 pair<iterator, bool>
// 第一个元素（pair.first）是一个指向插入位置的迭代器
// 第二个元素（pair.second）是一个布林值，表示插入是否成功
// 如果元素被成功插入，返回 true
// 如果元素已存在集合中，返回 false

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> count;
        for(int num:arr){
            count[num]++;
        }
        unordered_set<int> occur;
        for(auto& pair:count){
            if(!occur.insert((pair.second)).second){
                return false;
            }
        }
        return true;
    }
};