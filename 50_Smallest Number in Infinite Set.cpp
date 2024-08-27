// 2336. Smallest Number in Infinite Set
// runtime : 62 ms Beats 69.90%
// space : 40.72 MB Beats 63.89%

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
    set<int> added; // 判斷數字有無被加到過 minheap 裡
    priority_queue<int,vector<int>,greater<int>> minheap; // 存放 < current 已被刪除的數
    int current;
public:
    SmallestInfiniteSet() {
        current=1;
    }
    
    int popSmallest() {
        if(!minheap.empty()){
            int x=minheap.top();
            minheap.pop();
            added.erase(x);
            return x;
        }
        else{
            return current++;
        }
    }
    
    void addBack(int num) {
        if(num<current && added.find(num)==added.end()){ // num 大於或等於 current，表示這個數字還未被取出
            added.insert(num);
            minheap.push(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */