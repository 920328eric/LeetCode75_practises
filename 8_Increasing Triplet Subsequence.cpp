// 334. Increasing Triplet Subsequence
// runtime：78 ms Beats 81.95%
// space :114.33 MB Beats 32.70%
// O(1) extra space and O(n) time

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int numsLen = nums.size();
        int first = INT_MAX;
        int second = INT_MAX;
        for(int i = 0;i<numsLen;i++){
            if(nums[i]<=first){
                first = nums[i];
            }
            else if(nums[i]<=second){
                second = nums[i];
            }
            else{ // 只是單純確保一定會有一組序列滿足，但最後跑出來的不一定會是最終答案 ex:[20,100,10,12,5,13]
                return true;
            }
        }
        return false;
    }
};