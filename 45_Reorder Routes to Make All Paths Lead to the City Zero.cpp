// 1466. Reorder Routes to Make All Paths Lead to the City Zero
// runtime：269 ms Beats 69.44%
// space : 110.17 MB Beats 73.41%

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<pair<int, int>> adj[n]; 
        // 建構"雙向"鄰接表 adj[n]，建構了一個包含所有可能連接的雙向圖，並於鄰接表中新增兩個方向的連接：
        for (vector<int> e : connections) {
            adj[e[0]].push_back({e[1], 1}); // {e[1], 1} 表示從節點 e[0] 到節點 e[1] 的邊，1 表示這條邊需要反轉
            adj[e[1]].push_back({e[0], 0}); // {e[0], 0} 表示從節點 e[1] 到節點 e[0] 的邊，0 表示這條邊不需要反轉
        }
        return dfs(0, -1, adj); // 從節點 0 開始進行 DFS
    }
    int dfs(int node, int prnt, vector<pair<int, int>> adj[]) {
        int cnt = 0; // 需要反轉的邊的數量
        for (pair<int, int> ad : adj[node]) {

            if (ad.first == prnt) continue;
            // 如果鄰居是父節點，跳過（防止回溯）

            cnt += ad.second + dfs(ad.first, node, adj); 
            // 在 DFS 過程中計算需要反轉的邊數
            // ad.second 是目前邊是否需要反轉（1 需要，0 不需要），dfs(ad.first, node, adj) 遞迴呼叫 DFS 處理下一個節點
        }
        return cnt;
    }
};