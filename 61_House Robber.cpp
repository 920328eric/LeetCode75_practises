// 198. House Robber
// runtime : 0 ms Beats 100.00%
// space : 9.18 MB Beats 96.83%

// # Intuition
// 判斷到底要不要偷當前房子
// 
// 1.偷當前，就是之前最大數(i-2房屋為止的最大偷竊金額)+當前金額
// 2.不偷當前，就是 i-1 房屋為止的最大偷竊金額，可能包含了 i-1 房屋

// Time complexity:
// O(n)
// Space complexity:
// O(1)

class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int pre=0; // i-2 房屋為止的最大偷竊金額 
        int cur=0; // i-1 房屋為止的最大偷竊金額，可能包含了 i-1 房屋
        for(int i=0;i<n;i++){
            // 偷這個房屋: 那麼我們就不能偷前一個房屋，所以金額是 pre + nums[i]
            // 不偷這個房屋: 那麼最大金額與之前相同，所以金額是 cur
            int temp=max(pre+nums[i],cur);
            pre=cur;
            cur=temp;
        }
        return cur;
    }
};