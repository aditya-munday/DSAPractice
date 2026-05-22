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
  ListNode *removeElements(ListNode *head, int val) {
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *i = dummy;
    ListNode *j = head;

    while (j != nullptr) {
      if (val == j->val) {
        i->next = j->next;
      } else {
        i = i->next;
      }
      j = j->next;
    }

    return dummy->next;
  }
};