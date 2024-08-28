// 2336. Smallest Number in Infinite Set
// runtime : 60 ms Beats 74.19%
// space : 40.58 MB Beats 82.77%

// set.insert(1);
//
// for (const auto &s : set) {
//         cout << s << " ";
//     }
//
// set.erase(2); // 刪除 2 // 也可刪除不存在的元素
//
// set.clear(); // 清空所有元素
//
// set.empty()

class SmallestInfiniteSet {
private:
    priority_queue<int,vector<int>,greater<int>> minheap; // 存放 < current 已被刪除的數
    unordered_set<int> added; // 判斷數字有無被加到過 minheap 裡
    int current;
public:
    SmallestInfiniteSet() {
        current=1;
    }
    
    int popSmallest() {
        if(!minheap.empty()){
            int ans = minheap.top();
            minheap.pop();
            added.erase(ans);
            return ans;
        }
        else{
            return current++;
        }
    }
    
    void addBack(int num) {
        if(num < current && added.find(num)==added.end()){ // num 大於或等於 current，表示這個數字還未被取出
            minheap.push(num);
            added.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */