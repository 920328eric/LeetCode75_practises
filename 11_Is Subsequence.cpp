// topic：392. Is Subsequence
// runtime：0 ms Beats 100.00%
// space : 7.79 MB Beats 24.04%

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sLen = s.size();
        int tLen = t.size();
        int sPoint = 0;
        for(int i = 0;i<tLen;i++){
            if(s[sPoint] == t[i]){
                sPoint++;
            }
        }
        if(sPoint == sLen){
            return true;
        }
        else{
            return false;
        }
    }
};