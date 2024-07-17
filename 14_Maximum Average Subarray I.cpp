// 643. Maximum Average Subarray I
// runtime：115 ms
// space : 112.80 MB 
// O(n) time

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double tempsum = 0.0;
        double maxsum;
        for(int i = 0;i<k;i++){
            tempsum+=nums[i]; // sum of the nums which start from 0 to k-1
        }
        maxsum = tempsum;
        for(int j = k;j<nums.size();j++){
            tempsum = tempsum - nums[j-k] + nums[j]; // then cut of the nums[tail] and add nums[header+1],continue to folow this idea
            maxsum = max(maxsum,tempsum);
        }
        return maxsum/k;
    }
};