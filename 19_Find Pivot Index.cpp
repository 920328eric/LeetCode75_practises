// 724. Find Pivot Index
// runtime：16 ms
// space : 34.74 MB 

// 函數共有四個參數，其中前三個為必須，第四個為非必需。
// 若不指定第四個參數，則預設對範圍內的元素進行累加操作。
// accumulate(起始迭代器, 結束迭代器, 初始值, 自訂操作函數)
// int sum = accumulate(arr.begin(), arr.end(), 0); // 初值0 + (1 + 2 + 3 + 4 +... + 10)
// 補：int sum = accumulate(arr.begin(), arr.end(), 1, multiplies<int>()); // 初值1 * (1 * 2 * 3 * 4 *... * 10)

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = accumulate(nums.begin(),nums.end(),0);
        int leftsum = 0,rightsum;
        for(int i = 0;i<nums.size();i++){
            rightsum = total - leftsum - nums[i];
            if(leftsum == rightsum){
                return i;
            }
            leftsum+=nums[i]; // add the nums[i] before i becomes to be i+1
        }
        return -1;
    }
};