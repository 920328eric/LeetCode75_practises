// 2300. Successful Pairs of Spells and Potions
// runtime : 145 ms Beats 71.67%
// space : 100.99 MB Beats 83.36%

// # Approach
// 找到一組乘績的右半部都是 > success，所以必須先由小到大排序 potions

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int ss=spells.size();
        int ps=potions.size();
        vector<int> ans(ss,0); // 先全部設為 0，因為如果沒有任何一組乘績 > success 就為 0
        sort(potions.begin(),potions.end());
        for(int i=0;i<ss;i++){
            int first=0,end=ps-1;
            int current=-1; // 沒有任何一組乘績 > success，current 值就設 -1
            while(first<=end){
                int mid=first+(end-first)/2; // 避免溢位
                long long s=spells[i]; // 避免乘績溢位
                if(s*potions[mid]>=success){ // 找到一組乘績的右半部都是 > success
                    end=mid-1;
                    current=mid;
                }
                else{
                    first=mid+1;
                }
                if(current!=-1){ // 如果 current 值有改變，代表有找到一組乘績的右半部都是 > success
                    ans[i]=ps-current;
                }
            }
        }
        return ans;
    }
};