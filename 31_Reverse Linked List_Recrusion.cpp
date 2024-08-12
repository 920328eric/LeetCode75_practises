// 206. Reverse Linked List_Recursion
// runtime：2 ms Beats 84.92%
// space : 13.31 MB Beats 10.21%

//  1.	初始調用：
// 	    •	假設鏈表是 1 -> 2 -> 3 -> NULL。
// 	    •	第一次調用 reverseList(head)，head 指向節點 1。
// 	    •	然後遞歸調用 reverseList(head->next)，也就是 reverseList(2)。
// 	2.	第二次調用：
// 	    •	現在 head 指向節點 2。
// 	    •	再次遞歸調用 reverseList(head->next)，即 reverseList(3)。
// 	3.	第三次調用（到達鏈表末尾）：
// 	    •	現在 head 指向節點 3。
// 	    •	調用 reverseList(head->next)，此時 head->next 為 NULL，所以這裡進入了基礎條件，直接返回 head，也就是 3。
// 	4.	開始回溯並進行反轉：
// 	    •	回到第二次調用的上下文，此時 head 是 2，end 是 3（因為遞歸返回了 3）。
// 	    •	執行 head->next->next = head，這將 3->next 指向 2，鏈表變成 3 -> 2 -> NULL。
// 	    •	然後 head->next = nullptr，切斷 2 的原鏈接，避免形成循環。
// 	5.	繼續回溯：
// 	    •	回到第一次調用的上下文，此時 head 是 1，end 是 3（因為前一次回溯返回了 3）。
// 	    •	執行 head->next->next = head，這將 2->next 指向 1，鏈表變成 3 -> 2 -> 1 -> NULL。
//  	•	然後 head->next = nullptr，切斷 1 的原鏈接，完成反轉。

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
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr||head->next==nullptr){
            return head;
        }
        ListNode * end=reverseList(head->next);
        head->next->next=head;
        head->next=nullptr;
        return end;
    }
};