// 933. Number of Recent Calls
// runtime：112 ms Beats 49.92%
// space : 62.38 MB Beats 32.44%

class RecentCounter {
public:
    queue<int> q;
    
    // 構造函式，用來初始化隊列
    RecentCounter() {
        // 這裡即使不寫任何東西，構造函式仍然會被調用
    }
    
    int ping(int t) {
        q.push(t);
        while(!q.empty()&&q.front()<t-3000){
            q.pop();
        }
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */