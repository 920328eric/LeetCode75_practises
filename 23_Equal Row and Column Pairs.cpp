// 2352. Equal Row and Column Pairs
// runtime：58 ms Beats 91.15%
// space : 35.92  MB Beats 47.10%
// O(n^2 * log n) time

// 定義一個map對象
// map<int, string> mapStudent;
//  第一種 用insert函數插入pair
// mapStudent.insert(pair<int, string>(000, "student_zero"));
//  第二種 用insert函數插入value_type數據
// mapStudent.insert(map<int, string>::value_type(001, "student_one"));
//  第三種 用"array"方式插入
// mapStudent[123] = "student_first";
// mapStudent[456] = "student_second";

// vector<int>：是一個動態數組，元素按照插入順序存儲。
// unordered_set<int>：是一個基於哈希表的集合，元素無序存儲。
//  元素唯一性：
// vector<int>：可以存儲重複元素。
// unordered_set<int>：只存儲唯一元素，重複元素會被自動忽略。
//  插入操作：
// vector<int>：使用 push_back() 在尾部插入，時間複雜度 O(1)。
// unordered_set<int>：使用 insert()，平均時間複雜度 O(1)。
//  查找操作：
// vector<int>：需要遍歷整個數組，時間複雜度 O(n)。
// unordered_set<int>：使用 find()，平均時間複雜度 O(1)。
//  刪除操作：
// vector<int>：從中間刪除元素需要移動後續元素，時間複雜度 O(n)。
// unordered_set<int>：使用 erase()，平均時間複雜度 O(1)。
//  排序：
// vector<int>：可以使用 sort() 進行排序。
// unordered_set<int>：元素無序，不支持直接排序。
//  內存使用：
// vector<int>：連續內存，空間效率較高。
// unordered_set<int>：使用哈希表，可能占用更多內存。
//  遍歷：
// vector<int>：可以使用索引或迭代器遍歷。
// unordered_set<int>：只能使用迭代器遍歷。
//  總結：
// 如果需要快速查找、插入和刪除，並且元素唯一性很重要，使用 unordered_set。
// 如果需要保持元素的插入順序，允許重複元素，或者經常按索引訪問元素，使用 vector。

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int count = 0;
        map<vector<int>,int> rowmap; // unordered_map 沒有提供直接放入vector<int>
        for(const auto& row:grid){
            rowmap[row]++;
        }
        for(int i=0;i<n;i++){
            vector<int> col; 
            for(int j=0;j<n;j++){
                col.push_back(grid[j][i]);
            }
            count+=rowmap[col]; // 檢查是否在 rowMap 中存在，如果存在，rowMap[col] 會返回這個向量作為鍵在 map 中對應的值，也就是作為行出現的次數。
        }
        return count;
    }
};