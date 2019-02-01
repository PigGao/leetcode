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
    ListNode* swapPairs(ListNode* head) {
    	if(head==NULL)
    		return head;
    	ListNode *newhead = new ListNode(-1);
    	newhead->next = head;
      	ListNode *pre=newhead;
        ListNode *cur=newhead->next;
        ListNode *nex=cur->next;
  		while(pre->next&&pre->next->next)
  		{ 	
            cur = pre->next;
  			nex = cur->next;		
  			cur->next = nex->next;
            nex->next = pre->next;
  			pre->next = nex;
  			pre = cur;  			
  		}
  		return newhead->next;
    }
};