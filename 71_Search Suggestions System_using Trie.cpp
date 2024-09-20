// 1268. Search Suggestions System (using Trie)
// runtime : 805 ms Beats 7.97%
// space : 669.18 MB Beats 5.06%

// Approach
// 1.先架好 TrieNode 結構，裡頭包含 insert、search
// 2.主函數先把所有 products insert 到 TrieNode 裡
// 3.接著就可以在主函數裡，找到對應 prefix 的答案了

class Solution {
public:
    class Trie{
        public:
        vector<Trie*> child;
        bool isword;
        
        Trie(){
            child = vector<Trie*> (26, nullptr);
            isword=false;
        }
        
        void addWord(string word){
            Trie* node=this;
            
            for(char c : word){
                int index = c-'a';
                if(node->child[index]==nullptr)
                    node->child[index]=new Trie();
                
                node=node->child[index];
            }
            
            node->isword=true;
        }
        
        // 執行 DFS，找到給定前綴的所有單詞
        void searchWord(vector<string>& result, string partial, int& count){
            Trie* node=this;
            if(count>2) return; // 最多返回3個結果（count > 2）
            if(node->isword==true){
                result.push_back(partial);
                count++;
            }
            
            for(int i=0; i<26; i++){
                if(node->child[i]!=nullptr){
                    partial += (i+'a');
                    node->child[i]->searchWord(result, partial, count);
                    partial.pop_back();
                }
            }
        }
    };
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie* trie=new Trie();
        int n=searchWord.size();
        vector<vector<string>> result;
        
        for(string product : products) // 將所有產品添加到 Trie 中
            trie->addWord(product);

        string partial="";
        for(int i=0; i<n; i++){ // 尋找匹配的前綴並收集
            if(trie->child[searchWord[i]-'a']==nullptr){
                while(i<n){
                    result.push_back({});
                    i++;
                }    
            }
            else{
                vector<string> cprefix;
                partial+=searchWord[i];
                trie=trie->child[searchWord[i]-'a'];
                int count=0;
                
                trie->searchWord(cprefix, partial, count);
                
                result.push_back(cprefix);
            }
        }
        return result;
    }
};