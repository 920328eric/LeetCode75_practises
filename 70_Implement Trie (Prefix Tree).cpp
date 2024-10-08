// 208. Implement Trie (Prefix Tree)
// runtime : 40 ms Beats 86.78%
// space : 48.59 MB Beats 36.57%

// Trie 是一種樹狀結構，可以用來在大量字串中快速搜尋某個字串。
// 雖然這個問題也可以用 hash table 來解決，但在以下情況下，Trie 有其獨特的優勢：

// 1.找出每個有特定前綴的字串。
// 2.按照字典順序列出所有字串。

// hash table 在面對上述問題時有兩個缺點：

// 1.如果大部分的輸入字串都具有相同的前綴，hash table 相對於 Trie 會耗費更多的記憶體空間。
// 2.hash table 可能會發生碰撞，導致搜尋的時間複雜度達到 O(n)，其中 n 是插入的總資料量；
//   而 Trie 在執行搜尋時可以保持時間複雜度為 O(k)，其中 k 是搜尋字串的長度。

// Trie 的 root 是不含資料
// 每個 node 都包含一個 boolean 變數 isword，紀錄該 node 是不是一個單字的結尾。

// 示意圖：
//   root
//   |
//   c
//   |
//   a
//   |
//   t (end of word)(isword = true)

class TrieNode{
public:
    TrieNode * children[26];
    bool isword; 
    TrieNode(){
        for(int i=0;i<26;i++){
            children[i]=nullptr;
        }
        isword=false;
    }
};

class Trie {
private:
    TrieNode * root;
public:
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode * cur=root;
        for(char c:word){
            int index=c-'a'; // ASCII
            if(cur->children[index]==nullptr){
                cur->children[index]=new TrieNode();
            }
            cur=cur->children[index];
        }
        cur->isword=true;
    }
    
    bool search(string word) {
        TrieNode * cur=root;
        for(char c:word){
            int index=c-'a';
            if(cur->children[index]==nullptr){
                return false;
            }
            cur=cur->children[index];
        }
        return cur->isword; // 我們需要檢查最後一個節點是否被標記為單詞結尾，所以必須檢查最後一個字母的 isword 是否為 true
    }
    
    bool startsWith(string prefix) {
        TrieNode * cur=root;
        for(char c:prefix){
            int index=c-'a';
            if(cur->children[index]==nullptr){
                return false;
            }
            cur=cur->children[index]; 
        }
        return true; // 只要能夠遍歷完整個前綴而不返回 false，就意味著這個前綴存在，不需要檢查最後一個節點是否是單詞結尾
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */