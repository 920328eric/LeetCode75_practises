// 162. Find Peak Element
// runtime : 3 ms Beats 64.55%
// space : 11.60 MB Beats 59.62%

// # Intuition
//  「runs in O(log n) time」 means useing binary search

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int first=0,end=nums.size()-1;
        while(first<end){ // 相等的話就找到 peak 了
            int mid=first+(end-first)/2;
            if(nums[mid]>nums[mid+1]){ // 代表 nums[mid] 可能為 peak 或者 nums[mid] 的左邊有可能有 peak 
                end=mid; // 所以包括 mid
            }
            else{ // nums[mid]<nums[mid+1]
                first=mid+1; // 代表 nums[mid] 的右邊有可能有 peak，不包括 mid 是因為 peak 要為中間最大值
            }
        }
        return first; // 或 end 也可，因為 first == end 時就為 peak
    }
};