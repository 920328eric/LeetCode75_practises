// 238. Product of Array Except Self
// runtime：20 ms Beats 92.22%
// space :38.06 MB Beats 92.04%
// O(1) extra space and O(n) time

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int numsLen = nums.size();
        vector<int> output(numsLen,1);
        int sum = 0;
        int left = 1;
        for(int j = 0;j<numsLen;j++){
            output[j] = left;
            left *= nums[j];
        }
        int right = 1;
        for(int i = (numsLen-1);i>=0;i--){
            output[i] *= right;
            right *= nums[i];
        }
        return output;
    }
};