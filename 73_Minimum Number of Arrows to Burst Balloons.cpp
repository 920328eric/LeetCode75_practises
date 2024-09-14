// 452. Minimum Number of Arrows to Burst Balloons
// runtime : 259 ms Beats 45.42%
// space : 93.55 MB Beats 73.27%

// 最少箭頭問題的目標是最小化需要的箭頭數量。
// 並且在需要新箭頭時更新 pre，以最小化箭頭數量。

class Solution {
public:
    static bool compareEnd(vector<int>& p1,vector<int>& p2){
        return p1[1]<p2[1]; // 用結束時間來做排序（i+1 就是 p1, i 就是 p2，判斷交換的條件）
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),compareEnd);
        int ans=1,pre=0;
        for(int i=1;i<points.size();i++){
            if(points[i][0]>points[pre][1]){ // 後面的開始時間 如果大於 前一個的結束時間，那就要多加一支 arrows 
                ans+=1;
                pre=i; // 這時才更新結束時間，需要新箭頭時更新 pre，以最小化箭頭數量
        }
        return ans;
    }
};