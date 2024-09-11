// 1318. Minimum Flips to Make a OR b Equal to c
// runtime : 0 ms Beats 100.00%
// space : 7.50 MB Beats 55.63%

// & 1 用來取得數字的最右邊一位（最低位）的值

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips=0;
        while(a>0 || b>0 || c>0){ // 相當於只要還有一數的二進位 bit = 1，就要持續下去比較
            int bita=a&1,bitb=b&1,bitc=c&1; // 取得數字的最後一位
            if(bitc==0){
                if(bita==1&&bitb==1){ // 要翻兩次，所以 +2
                    flips+=2;
                }
                else if(bita==1||bitb==1){ // 只需翻一次，所以 +1
                    flips+=1;
                }
            }
            else{
                if(bita==0&&bitb==0){ // 只需翻一次，所以 +1
                    flips+=1; 
                }
            }
            a=a>>1;b=b>>1;c=c>>1; // 右移每個數一位，就會達到依序看每一位數是否需要翻，才會符合題目條件
        }
        return flips;
    }
};