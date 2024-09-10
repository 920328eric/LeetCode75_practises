// 338. Counting Bits
// runtime : 0 ms Beats 100.00%
// space : 9.23 MB Beats 80.50%

// bitwise left shift <<
// bitwise right shift >>
// 0001 << 1 = 0010
// 1000 >> 1 = 0100

// bitwise AND &.        
// 0 & 0 = 0
// 0 & 1 = 0
// 1 & 0 = 0
// 1 & 1 = 1

// bitwise OR |
// 0 | 0 = 0
// 0 | 1 = 1
// 1 | 0 = 1
// 1 | 1 = 1

// bitwise XOR ^
// 0 ^ 0 = 0
// 0 ^ 1 = 1
// 1 ^ 0 = 1
// 1 ^ 1 = 0

// bitwise NOT ~
// ~ 0 = 1
// ~ 1 = 0

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        for(int i=1;i<=n;i++){
            ans[i]=ans[i&(i-1)]+1; // i & (i-1) 找到一個比 i 稍小的數，這個數的二進制表示中 1 的個數恰好比 i 少一個，所以最後 +1
        }
        return ans;
    }
};