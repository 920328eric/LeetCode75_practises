// 2462. Total Cost to Hire K Workers
// runtime : 131 ms Beats 35.35%
// space : 76.99 MB Beats 64.72%

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int first=0;
        int end=costs.size()-1;
        priority_queue<int,vector<int>,greater<int>> minheapf; // 存放前半部，並由小到大排好
        priority_queue<int,vector<int>,greater<int>> minheape; // 存放後半部，並由小到大排好
        long long ans=0;
        int num1,num2; // 前後半部分別的最小值
        while(k>0){
            k-=1;
            while(minheapf.size()<candidates && first<=end){ // size不夠就補齊
                minheapf.push(costs[first++]);
            }
            while(minheape.size()<candidates && first<=end){ // size不夠就補齊
                minheape.push(costs[end--]);
            }
            if(!minheapf.empty()){
                num1=minheapf.top();
            }
            else{
                num1=INT_MAX; // 確保一定會比較大
            }
            if(!minheape.empty()){
                num2=minheape.top();
            }
            else{
                num2=INT_MAX;
            }
            if(num1<=num2){ // 相等也是刪去前半部
                ans+=num1;
                minheapf.pop();
            }
            else{
                ans+=num2;
                minheape.pop();
            }
        }
        return ans;
    }
};