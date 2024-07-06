// topic：345. Reverse Vowels of a String
// runtime：3 ms
// space : 9.2 MB

// key : reverse(vowels.begin(),vowels.end());

class Solution {
public:
    string reverseVowels(string s) {
        int sLen = s.size();
        string vowels;
        int j = 0;
        for(int i = 0;i<sLen;i++){
            if( s[i]=='a' || s[i]=='e' || s[i]=='i'|| s[i]=='o'|| s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I'|| s[i]=='O'|| s[i]=='U'){
                vowels +=s[i];
            }
        }
        reverse(vowels.begin(),vowels.end());
        for(int i = 0;i<sLen;i++){
            if( s[i]=='a' || s[i]=='e' || s[i]=='i'|| s[i]=='o'|| s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I'|| s[i]=='O'|| s[i]=='U'){
                s[i] = vowels[j];
                j++;
            }
        }

        return s;
    }
};