// 739. Daily Temperatures
// runtime : 117 ms Beats 64.53%
// space : 101.30 MB Beats 71.51%

// key : Monotonic Stack 的概念是讓 stack 內的元素保持某種順序

// 此題 stack 中的元素對應的氣溫會按照索引位置保持由下而上遞減的順序（因為是要找到變暖的那天），
// 當遇到今天溫度比 stack.top() 還大或相等的溫度時，藉由 stack.pop() 從 stack 裡找出哪一天比今天更大
// 最後藉由索引值就會知道差了幾天才變暖

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> ans(n,0);
        stack<int> t;
        for(int i=n-1;i>=0;i--){
            while(!t.empty()&&temperatures[i]>=temperatures[t.top()]){ // 確保 stack 中的元素對應的氣溫會按照索引位置保持由下而上遞減的順序
                t.pop(); // 當遇到今天溫度比 stack.top() 還大或相等的溫度時，藉由 stack.pop() 從 stack 裡找出哪一天比今天更大
            }
            if(!t.empty()){
                ans[i]=t.top()-i; // 就會知道差了幾天才變暖，因為上方的 while 已經讓 stack 中的元素對應的氣溫按照索引位置保持由下而上遞減的順序
            }
            t.push(i); // 因為自己不會跟自己做比較，所以最後才把自己加到 stack 裡
        }
        return ans;
    }
};