// 875. Koko Eating Bananas
// runtime : 28 ms Beats 76.92%
// space : 22.53 MB Beats 10.50%

// # Approach
//     1.由 1 到 最大堆香蕉數，一個一個去算加起來的時間跟 h 做比較，看有無超過時間
//     2.除法取上限公式：(x + y - 1) / y

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        sort(piles.begin(),piles.end());
        int start=1; // 最小有可能一次吃一根
        int end=piles[n-1];
        while(start<=end){
            int mid=start+(end-start)/2;
            long long sum=0; // 避免溢位
            for(int i=0;i<n;i++){
                sum+=(piles[i]+mid-1)/mid; // 一個一個去除並取上限，加起來的時間，跟 h 做比較
            }
            if(sum>h){ // 花太多時間，所以要吃快一點，所以往右找
                start=mid+1;
            }
            else{ // 可能花剛好時間，或花太少時間，所以可以吃慢一點，所以往左找
                end=mid-1;
            }
        }
        return start; // 舉個例子就會知道要輸出 start，還有 while 結束的條件也是 start > end
    }
};