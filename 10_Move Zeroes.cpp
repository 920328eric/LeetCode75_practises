// topic：283. Move Zeroes
// runtime：15 ms Beats 68.14%
// space : 21.94 MB Beats 15.82%

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int numsLen = nums.size();
        int order = 0; // to see the numbers of !0
        for(int i = 0;i<numsLen;i++){
            if(nums[i] != 0){
                nums[order++] = nums[i];
            }
        }
        for(int j=order;j<numsLen;j++){
            nums[order++] = 0;
        }
    }
};