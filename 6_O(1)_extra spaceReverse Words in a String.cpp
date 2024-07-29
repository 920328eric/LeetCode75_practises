// topic：151. Reverse Words in a String
// runtime：0 ms Beats 100.00%
// space : 8.06 MB Beats 99.05%
// O(1) extra space

class Solution {
public:
    string reverseWords(string s) {
        s.erase(0,s.find_first_not_of(' '));
        s.erase(s.find_last_not_of(' ')+1);

        reverse(s.begin(),s.end());
        int slen = s.size();
        int start = 0;
        int index = 0;
        bool isfirst = true;
        for(int i = 0;i<=slen;i++){ // 會少看最後一位字母，所以<=
            if(s[i] == ' ' || i == slen){
                if(i>start){ // 確保不處理連續空格
                    reverse(s.begin()+start,s.begin()+i);
                    if(!isfirst){
                        s[index]=' ';
                        index+=1;
                    }
                    for(int j = start;j<i;j++){
                        s[index] = s[j];
                        index+=1;
                    }
                    isfirst = false;
                }
                start = i+1;;
            }
        }
        s.resize(index);
        return s;
    }
};