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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            delete head;
            return nullptr;
        }
        // slow 被聲明為 ListNode* 類型，意味著它是一個指向 ListNode 結構的指針
        // 這行代碼將 head 的值（即第一個節點的地址）賦給 slow，使 slow 指向鏈表的第一個節點
        ListNode * slow=head;
        ListNode * fast=head;
        ListNode * pre=nullptr;
        while(fast!=nullptr&&fast->next!=nullptr){
            fast=fast->next->next;
            pre=slow; // stores the previous position of slow
            slow=slow->next;
        }
        pre->next=slow->next;
        delete slow;
        return head;
    }
};