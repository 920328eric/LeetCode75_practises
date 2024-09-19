// 399. Evaluate Division
// runtime：0 ms Beats 100.0%
// space : 10.98 MB Beats 89.12%

class Solution {
    unordered_map<string, vector<pair<string, double>>> adj; // 用於儲存圖的鄰接表，包含目標節點和對應的權重（即除法結果）
    unordered_map<string, int> visit; // 用於在 DFS 過程中標記已訪問的節點
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        adj.clear(); // 確保每次調用 calcEquation 函數時都從一個空白的圖開始構建
        for (size_t i = 0; i < equations.size(); i++) {
            // 對於每個方程式 a/b = k，在圖中加兩條邊：從 a 到 b，權重為 k，從 b 到 a，權重為 1/k
            // 使得圖是無向的，可以在兩個方向上進行除法運算
            adj[equations[i][0]].push_back({equations[i][1], values[i]});
            adj[equations[i][1]].push_back({equations[i][0], 1.0 / values[i]});
        }
        vector<double> ans;
        for (const vector<string>& query : queries) {
            visit.clear();

            // 提取查詢的起始節點和目標節點
            const string& source = query[0]; // 起始節點，計算的分數的分子
            const string& destination = query[1]; // 目標節點，代表分母
            
            // 初始化結果的乘積為 1
            double prod = 1;

            if (adj.find(source) == adj.end() || adj.find(destination) == adj.end()) // 沒有在任何方程式中出現過
                ans.push_back(-1);
            else if (dfs(source, destination, prod)) // 起始節點和目標節點都在圖中，使用 DFS 尋找一條從起始到目標的路徑
                ans.push_back(prod);
            else // DFS 沒有找到路徑，起始節點和目標節點都在圖中，但它們之間沒有連接
                ans.push_back(-1);
        }
        return ans;
    }

    // node：當前正在訪問的節點，destination：目標節點，prod：用於累積路徑上的乘積
    bool dfs(const string& node, const string& destination, double &prod) {
        if (node == destination) return true;
        visit[node] = 1;
        for (const pair<string, double>& edge : adj[node]) {
            // v：鄰居節點的名稱，w：從當前節點到這個鄰居節點的邊的權重（即除法值）
            const string& v = edge.first;
            const double& w = edge.second;

            // 如果鄰居節點還沒有被訪問（避免循環），而且從這個鄰居節點出發能夠到達目標節點
            if (!visit[v] && dfs(v, destination, prod)) {
                prod *= w; // 找到了路徑，將當前邊的權重乘入總乘積中
                return true;
            }
        }
        return false;
    }
};