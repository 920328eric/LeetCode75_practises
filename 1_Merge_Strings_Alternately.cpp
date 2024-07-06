// topic：1768. Merge Strings Alternately
// runtime：0 ms
// space : 7.6 MB

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string merged;
        int word1Length = word1.length();
        int word2Length = word2.length();

        if(word1Length>word2Length){
            for(int i = 0;i<word2Length;i++){
                merged += word1[i];
                merged += word2[i];
            }
            for(int j = word2Length;j<word1Length;j++){
                merged += word1[j];
            }
        }
        else if(word1Length<word2Length){
            for(int i = 0;i<word1.length();i++){
                merged += word1[i];
                merged += word2[i];
            }
            for(int j = word1Length;j<word2Length;j++){
                merged += word2[j];
            }
        }
        else{
            for(int i = 0;i<word1Length;i++){
                merged += word1[i];
                merged += word2[i];
            }
        }

        return merged;
    }
};