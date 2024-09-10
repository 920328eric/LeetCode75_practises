// 136. Single Number
// runtime : 11 ms Beats 82.26%
// space : 19.62 MB Beats 30.20%

// bitwise XOR ^
// 相異為 1 
// 相同為 0

// 8 => 1000
// 15 =>1111
// 8 ^ 15 = 7 => 0111
// 7 ^ 8 = 15 => 1111

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int num:nums){
            ans=ans^num; // 自己和自己 XOR 為 0，因為完全ㄧ模一樣，相同為 0，所以到最後就只會剩只有一個數的那個，0 和任何數 XOR 就會是那個數，因為相異為 1 
        }
        return ans;
    }
};