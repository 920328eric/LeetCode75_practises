// 435. Non-overlapping Intervals
// runtime : 236 ms Beats 66.52%
// space : 93.42 MB Beats 92.92%

// sort() 底層為 intro sort，是以 Quick Sort 為核心的混合型排序法。在一般 Quick Sort 流程加入以下變化：
// 1.在元素少到一定程度時使用 Insertion Sort
// 2.在遞迴超過一定深度時改用 Heap Sort

// sort() 客制作法
// sort 內部有兩層迴圈，不斷地針對 vector 的 index 0 頭掃到 index n 尾，直到排序結束為止，
// 而迴圈每次都會將 i+1 與 i 帶入 mycompare 的參數，i+1 就是 a, i 就是 b，
// 如此一來 a > b 就會將 i+1 與 i 交換 swap，這樣就會一直將越大的數值排越前面
//
// ex: 
// bool mycompare(int a, int b) {
//     return a > b; // 降序排列
// }
// int main() {
//     sort(v.begin(), v.end(), mycompare);
// }

// greedy的連續應用：
// 不僅要選擇第一個結束最早的區間，還要連續選擇所有可能的非重疊區間
// 通過不斷更新 pre，確保了算法可以找到最多的非重疊區間

class Solution {
public:
    static bool compareEnd(vector<int>& i1,vector<int>& i2){
        return i1[1]<i2[1]; // 用結束時間來做排序（i+1 就是 i1, i 就是 i2，判斷交換的條件）
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),compareEnd);
        int pre=0;
        int ans=0;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<intervals[pre][1]){ // 後面的開始時間 如果小於 前一個的結束時間，那就要刪掉，因為會重疊
                ans+=1;
            }
            else{
                pre=i; // 為了連續選擇所有可能的非重疊區間，所以要更新成結束時間更晚的 intervals
            }
        }
        return ans;
    }
};