/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        while(head==NULL)
            return NULL;
        ListNode* newhead =new ListNode(-1);
        newhead->next = head;
        int num=1;
        while(head=head->next)
            num++;
        int pos=num-n;
        ListNode* cur = newhead;
        while(pos>0)
        {
            pos--;
            cur = cur->next;
        }
        cur->next = cur->next->next;
        
        return newhead->next;
        
    }
};