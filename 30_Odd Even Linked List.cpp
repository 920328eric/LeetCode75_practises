// 328. Odd Even Linked List
// runtime：9 ms Beats 36.61%
// space : 15.36 MB Beats 32.73%

// in O(1) extra space complexity and O(n) time complexity

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
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode * odd=head;
        ListNode * even=head->next;
        ListNode * pre=head; // to store head->next
        pre=head->next;
        while(even!=nullptr&&even->next!=nullptr){ // only the last even will become nullptr 
            odd->next=even->next;
            odd=odd->next; // because odd->next had become even->next,you only have to move odd to next position one time 
            even->next=odd->next;
            even=even->next; // because even->next had become odd->next,you only have to move even to next position one time 
        }
        odd->next=pre; // let the last one in odd to point to the first one in even,so you have to make odd->next become head->next (head has not been changed)
        return head;
    }
};