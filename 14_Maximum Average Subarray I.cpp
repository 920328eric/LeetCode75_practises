// 643. Maximum Average Subarray I
// runtime：115 ms
// space : 112.80 MB 
// O(n) time

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxnum = 0.0;
        double sum = 0.0;
        for(int i = 0;i<k;i++){
            sum+=nums[i]; // sum of the nums which start from 0 to k-1
        }
        maxnum = sum;
        for(int j=k;j<nums.size();j++){ 
            sum = sum - nums[j-k] + nums[j]; // then cut of the nums[tail] and add nums[header+1],continue to folow this idea
            maxnum = max(maxnum,sum);
        }
        return maxnum/k;
    }
};