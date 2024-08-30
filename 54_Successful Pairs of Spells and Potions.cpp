// 2300. Successful Pairs of Spells and Potions
// runtime : 160 ms Beats 20.41%
// space : 100.90 MB Beats 87.84%

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int ns=spells.size();
        int ps=potions.size();
        vector<int> ans(ns,0); // 先全部設為 0，因為如果沒有任何一組乘績 > success 就為 0
        sort(potions.begin(),potions.end());
        for(int i=0;i<ns;i++){
            int start=0,end=ps-1;
            int current=-1; // 沒有任何一組乘績 > success，current 值就設 -1
            while(start<=end){
                int mid=start+(end-start)/2; // 避免溢位
                long long num=spells[i]; // 避免乘績溢位
                if(num*potions[mid]>=success){ // 找到一組乘績的右半部都是 > success
                    end=mid-1;
                    current=mid; 
                }
                else{
                    start=mid+1;
                }
            }
            if(current!=-1){ // 如果 current 值有改變，代表有找到一組乘績的右半部都是 > success
                ans[i]=ps-current;
            }
        }
        return ans;
    }
};