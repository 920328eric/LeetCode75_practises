// 206. Reverse Linked List_Iterative
// runtime：8 ms Beats 23.59%
// space : 12.99 MB Beats 41.32%

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
        ListNode * pre=nullptr;
        ListNode * cur=head;
        while(cur!=nullptr){
            ListNode * forw=cur->next;
            cur->next=pre;
            pre=cur;
            cur=forw;
        }
        return pre;
    }
};