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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int num = lists.size();
        if(num==0)
            return NULL;
        int count=1;
        while(count<num)
        {
            for(int i=0;i<num-count;i=i+count*2)
                lists[i] = mergeTwoLists(lists[i],lists[i+count]);
            count = count*2;
        }
        return lists[0];
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode *head  =new ListNode(-1);
        ListNode *res = head;
        while(l1||l2)
        {
            if(l1&&l2)
            {
                if(l1->val>l2->val)
                {
                    head->next = l2;
                    l2 = l2->next;
                    head = head->next;
                }
                else
                {
                    head->next = l1;
                    l1 = l1->next;
                    head = head->next;
                }
            }
            else if(l1)
            {
                head->next = l1;
                l1 = l1->next;
                head = head->next;
            }
            else if(l2)
            {
                head->next = l2;
                l2 = l2->next;
                head = head->next;
            }
        }
        return res->next;
    }
};