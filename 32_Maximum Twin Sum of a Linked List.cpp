// 2130. Maximum Twin Sum of a Linked List
// runtime：179 ms Beats 61.95%
// space : 119.23 MB Beats 65.80%

// O(1) extra space

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
    int pairSum(ListNode* head) {
        ListNode * slow=head;
        ListNode * fast=head;
        ListNode * pre=nullptr;
        ListNode * temp=nullptr;
        // reverse the first half of the linked list and find the midpoint at the smae time
        while(fast!=nullptr&&fast->next!=nullptr){
            fast=fast->next->next;
            // reverse the first half of the linked list
            temp=slow->next;
            slow->next=pre;
            pre=slow;
            slow=temp;
        }
        int maxsum=0;
        // pre is the head node of the first half after inversion
        // slow is the head node of the second half
        while(pre!=nullptr){ // or slow!=nullptr
            maxsum=max(maxsum,pre->val+slow->val);
            pre=pre->next;
            slow=slow->next;
        }
        return maxsum;
    }
};