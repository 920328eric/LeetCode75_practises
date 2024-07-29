// 2215. Find the Difference of Two Arrays
// runtime：32 ms Beats 83.73%
// space : 37.14 MB Beats 28.51%
// O(n) time and O(n) extra space 

// 1.unordered_set<int> set; // 容器裡面的元素是唯一的，具有不重複的特性，時間複雜度為常數級別O(1)，但消耗較多的記憶體，空間複雜度較高
//   set.insert(1);  // 插入元素
// 2.unordered_map<string, int> map;
//   map["key"] = 1;  // 插入鍵值對

// vector<int> ans1,ans2; 要用 ans1.push_back(num);

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        // delete duplicate elements by using unordered_set
        unordered_set<int> set1(nums1.begin(),nums1.end()); 
        unordered_set<int> set2(nums2.begin(),nums2.end());
        vector<int> ans1,ans2;

        for(int num:set1){
            if(set2.find(num)==set2.end()){ // represent that there is no element in set2 that is alse in set1
                ans1.push_back(num);
            }
        }
        for(int num:set2){
            if(set1.find(num)==set1.end()){ // represent that there is no element in set1 that is alse in set2
                ans2.push_back(num);
            }
        }
        return {ans1,ans2};
    }
};