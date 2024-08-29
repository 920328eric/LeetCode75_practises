// 2542. Maximum Subsequence Score
// runtime : 143 ms Beats 90.36%
// space : 91.22 MB Beats 87.22%

// pair<int,string> myPair(100, "Tom");
// myPair.first 
// myPair.second

// make_pair 是一個方便的函數，用來建立 pair，它可以自動推斷元素的類型
// auto anotherPair = make_pair(3.14, "Hello World");

// pair 支援比較運算子，你可以使用 ==, !=, <, >, <=, 和 >= 來比較兩個 pair 對象
// if (pair1 == pair2) {
//       cout << "相等\n";
// } 

// vector<pair<int,string>> keyValuePairs;
// vector<pair<int,string>> keyValuePairs(n); // 指定有 n 個 pair  

// keyValuePairs.push_back(make_pair(1, "One"));

// sort(pairs.begin(), pairs.end()); // 由小到大排序


// # Approach
// nums1加總最大（所以用minheap，刪最小） * nums2最小值（所以排序，由大到小）
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        vector<pair<int,int>> pairs(n);
        for(int i=0;i<n;i++){
            pairs[i]={nums2[i],nums1[i]}; // 把對應關係合起來
        }
        sort(pairs.begin(),pairs.end()); // 依據 nums2[i] 去由小到大排序，因為答案是要乘上最小的 nums2[i] 
        priority_queue<int,vector<int>,greater<int>>  minheap;
        long long currentsum=0,maxsum=0;
        for(int i=n-1;i>=0;i--){ // 由大到小是因為，一定是乘上最小的那個 pairs[i].first，也就是nums2[i] (題目要求乘上min)
            minheap.push(pairs[i].second);
            currentsum+=pairs[i].second;
            if(minheap.size()>k){
                currentsum-=minheap.top(); // 扣掉最小的數，以保持加總是最大的
                minheap.pop();
            }
            if(minheap.size()==k){
                maxsum=max(maxsum,currentsum*pairs[i].first);
            }
        }
        return maxsum;
    }
};