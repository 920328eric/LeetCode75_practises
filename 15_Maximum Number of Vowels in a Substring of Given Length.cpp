// 1456. Maximum Number of Vowels in a Substring of Given Length
// runtime：20 ms Beats 62.51%
// space : 11.54 MB Beats 24.06%

class Solution {
public:
    int maxVowels(string s, int k) {
        int maxc = 0;
        int count = 0;
        for(int i = 0;i<k;i++){
            if(isVowel(s[i])){
                count++; // sum of the s[i] which s[i] isVowel from i to k-1
            }
        }
        maxc = count;
        for(int j = k;j<s.size();j++){
            if(isVowel(s[j-k])){ 
                count--; // because will cut of the s[tail] if s[tail] isVowel
            }
            if(isVowel(s[j])){
                count++; // because will add of the s[header+1] if s[header+1] isVowel
            }
            maxc = max(maxc,count); 
        }
        return maxc;
    }
    bool isVowel(char a){
        if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u'){
            return true;
        }
        return false;
    }
};