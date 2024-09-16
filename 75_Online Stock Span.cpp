// 901. Online Stock Span
// runtime : 164 ms Beats 79.42%
// space : 90.46 MB Beats 38.13%

class StockSpanner {
public:
    stack<pair<int,int>> p; // 結構為 {span總數目,price(當前的價格)}
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span=1; // 任何一個的初始值為 1，因為包括自己 
        while(!p.empty()&&price>=p.top().second){ // 確保 stack 中會按照 price 大小保持由下而上遞減的順序
            span+=p.top().first; // 等於同時紀錄在這個數之前有幾個比此數小，下次再加上這個數的 span 就會知道共有多少 span 了
            p.pop(); // pop 掉的數就記載在比他大的數的 span 總數裡
        }
        p.push({span,price});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */