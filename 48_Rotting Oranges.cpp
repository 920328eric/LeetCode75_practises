// 994. Rotting Oranges
// runtime：3 ms Beats 84.52%
// space : 16.09 MB Beats 96.67%

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int total = 0, count = 0;
        queue<pair<int, int>> q;

        // 腐爛的橘子（值為 2）將它們加入到 queue 中，新鮮和腐爛的橘子（值為 1 或 2）統計橘子的總數
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2)
                    q.push({i, j});
                if (grid[i][j] != 0)
                    total++;
            }
        }

        // 定義四個相鄰的方向（上、下、左、右）
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        // BFS 逐步腐爛相鄰的新鮮橘子
        int ans = 0;
        while (!q.empty()) {
            int k = q.size();
            count += k; // 當前這一輪要處理的腐爛橘子數
            while (k--) {
                int y = q.front().second, x = q.front().first; // queue 中取出一個腐爛橘子的坐標 (y, x)
                q.pop();
                for (int i = 0; i < 4; i++) { // 遍歷四個方向（上、下、左、右）
                    int nx = x + dx[i], ny = y + dy[i]; // dx 和 dy 是兩個方向向量，分別表示水平方向（dx）和垂直方向（dy）的移動
                    
                    // 檢查坐標有無超出格子，同時檢查腐爛橘子周圍是否有新鮮橘子
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny] != 1) 
                        continue;
                    
                    grid[nx][ny] = 2;
                    q.push({nx, ny});
                }
            }
            if (!q.empty())
                ans++;
        }

        // 檢查腐爛的橘子數量 count 是否等於總橘子數量 total
        if (total == count)
            return ans;
        return -1;
    }
};