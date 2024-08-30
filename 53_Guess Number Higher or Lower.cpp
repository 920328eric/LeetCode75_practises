// 374. Guess Number Higher or Lower
// runtime : 2 ms Beats 55.19%
// space : 7.54 MB Beats 58.64%

// # Approach
// 
// 1. 其實就是藉由 guess(int num) 這個函數，去執行 Binary search
// 2. 同時注意 int 溢位問題

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int start=1;
        int end=n;
        int mid;
        while(start<=end){
            mid=start + (end-start)/2; // 避免 int 溢位
            if(guess(mid)==-1){
                end=mid-1; // end 變到 min 的前一格
            }
            else if(guess(mid)==1){
                start=mid+1; // start 變到 min 的後一格
            }
            else{
                return mid;
            }
        }
        return -1; // 如果找不到這個數字
    }
};