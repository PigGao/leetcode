
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
    	if(head==NULL||k==1)
    		return head;
    	ListNode *newhead = new ListNode(-1);
    	int num=0;
    	newhead->next = head;
    	ListNode *pre=newhead;
        ListNode *cur=newhead;
        ListNode *nex;
    	while(cur=cur->next)
  			num++;
  		while(num>=k)
  		{
  			cur = pre->next;
  			nex = cur->next;
  			for(int i=1;i<k;++i)
  			{
  				cur->next = nex->next;
  				nex->next = pre->next;
  				pre->next = nex;
  				nex = cur->next;
  			}
  			pre = cur;
  			num = num-k;
  		}
  		return newhead->next; 
    }
};