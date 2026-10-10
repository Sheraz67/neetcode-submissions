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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*curr = head;
        int k = 0;
        while(curr!=nullptr)
        {
            k++;
            curr = curr->next;
        }
        curr = head;
        int remove = k - n;
        if(remove == 0)
        {
            return head->next;
        }
        curr = head;
        for(int i = 0; i < k-1;i++)
        {
            if(remove == (i+1))
            {
                curr->next=curr->next->next;
                break;
            }
            curr = curr->next;
        }
        return head;


    }
};
