// 1679. Max Number of K-Sum Pairs
// runtime：120 ms
// space : 76.68 MB 
// O(n) time

// https://shengyu7697.github.io/std-map/
// map 容器會排序，會根據鍵值來進行排序
// map.first：第一個稱為(key)鍵值，在 map 裡面，(key)鍵值不會重複
// map.second：第二個稱為(key)鍵值對應的數值(value)

// map 和 unordered_map 的區別：
// map 是有序的，它使用紅黑樹實現，會自動按鍵值排序。 O(log n)
// unordered_map 是無序的，它使用哈希表實現，不會自動排序。 O(1)

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> exist; // to store how many each num's complement exist 
        int operation = 0;
        for(int num : nums){
            int complement = k - num;
            if(exist[complement]>0){ // num's complement exist in exist[]
                operation++;
                exist[complement]--;
            }
            else{
                exist[num]++; // if num's complement not exist in exist[],store num in exist[] 
            }
        }
        return operation;
    }
};