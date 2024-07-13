// 443. String Compression
// runtime：0 ms
// space : 14.06 MB 
// O(1) extra space

// countstr 是一個字串（string），用於暫時儲存數字的字元表示。雖然它的大小可能會根據壓縮後的計數而變化，
// 但它在每次迭代後都會被重置，而且其最大長度是有限的（因為整數的位數是有限的）。因此，它也可以被視為使用常量空間。

class Solution {
public:
    int compress(vector<char>& chars) {
        int charsLen = chars.size();
        char temp = chars[0];
        int count = 0;
        string countstr = "";
        int resizenum = 0;
        if(charsLen == 1){
            chars[0] = temp;
            return 1;
        }
        for(int i = 0;i<=charsLen;i++){
            if(i == charsLen){
                chars[resizenum] = temp;
                resizenum++;
                if(count > 1){
                    countstr = to_string(count);
                    for(int j = 0;j<countstr.size();j++){
                        chars[resizenum] = countstr[j];
                        resizenum++;
                    }
                }
                if(i<charsLen){
                    temp = chars[i];
                    count = 0;
                }
            }
            else if(temp != chars[i]){ // 為了防止 i == charsLen 的時候訪問越界
                chars[resizenum] = temp;
                resizenum++;
                if(count > 1){
                    countstr = to_string(count);
                    for(int j = 0;j<countstr.size();j++){
                        chars[resizenum] = countstr[j];
                        resizenum++;
                    }
                }
                if(i<charsLen){
                    temp = chars[i];
                    count = 0;
                }
            }
            count++;
        }
        return resizenum;
    }
};