// 1493. Longest Subarray of 1's After Deleting One Element
// runtime：44 ms
// space : 58.96 MB 

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int start = 0,end;
        int count = 0;
        int maxsum = 0;
        for(end = 0;end<nums.size();end++){
            if(nums[end]==0){
                count++;
            }
            while(count>1){ // to easure the sliding window only have one zero
                if(nums[start]==0){
                    count--;
                }
                start++;
            }
            maxsum = max(maxsum,end-start); // end - start = end - start + 1 - 1
        }
        if(maxsum == nums.size()){ // if the sliding window don't have any zero
            maxsum-=1;
        }
        return maxsum;
    }
};