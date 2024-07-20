// 1004. Max Consecutive Ones III
// runtime：24 ms
// space : 58.14 MB 

// 精闢的算法，只能背起來
// 1~3 共有 （3 - 1） + 1 位數

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start = 0,end;
        int count = 0;
        for(end = 0;end<nums.size();end++){
            if(nums[end] == 0){
                count++;
            }
            if(count>k){
                if(nums[start] == 0){
                    count--;
                }
                start++;
            }
        } // end = nums.size()
        return end-start;
    }
};