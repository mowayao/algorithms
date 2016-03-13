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
    bool hasCycle(ListNode *head) {
        ListNode *h1 = head, *h2 = head;
        while(h1!=NULL) {
            if(h1->next != NULL) h1 = h1->next;
            else return false;
            if(h2->next != NULL && h2->next->next != NULL) h2 = h2->next->next;
            else return false;
            if(h1==h2) return true;
        }
        return false;


    }
};
