// 2095. Delete the Middle Node of a Linked List
// runtime：604 ms Beats 23.97%
// space : 299.77 MB Beats 23.99%

// 第一個節點稱為 head。
// 最後一個節點的下一個指針通常指向 nullptr。
// int * p1 = nullptr;  // 正確的初始化空指針
// int * p2 = NULL;     // 舊式的初始化方法,不推薦
// int * p3 = 0;        // 也是舊式的初始化方法,不推薦
// head == nullptr 就是 head 不存在
// 當 head == nullptr 時： 在這種情況下，delete head; 實際上不會做任何事情。C++ 標準規定，對 nullptr 使用 delete 是安全的，不會造成任何問題
// delete i; // 釋放使用的記憶體空間

