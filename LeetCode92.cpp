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
  ListNode *reverse(ListNode *head) {

    ListNode *curr = head;
    ListNode *prev = nullptr;
    ListNode *fwd = nullptr;

    while (curr != nullptr) {
      fwd = curr->next;
      curr->next = prev;
      prev = curr;
      curr = fwd;
    }

    return prev;
  }

  ListNode *merge(ListNode *list1, ListNode *list2) {
    if (!list1)
      return list2;
    ListNode *temp = list1;
    while (list1 != nullptr) {
      if (temp->next == nullptr) {
        temp->next = list2;
        break;
      }
      temp = temp->next;
    }
    return list1;
  }

  ListNode *reverseBetween(ListNode *head, int left, int right) {
    if (head->next == nullptr)
      return head;
    int count = 1;

    ListNode *LeftList = new ListNode(-1);
    LeftList->next = head;
    ListNode *temp = LeftList;

    while (count < left) {
      temp = temp->next;
      count++;
    }

    ListNode *MiddleList = temp->next;
    temp->next = nullptr;
    temp = MiddleList;

    while (count < right) {
      temp = temp->next;
      count++;
    }

    ListNode *RightList = temp->next;
    temp->next = nullptr;
    MiddleList = reverse(MiddleList);

    ListNode *first = merge(LeftList->next, MiddleList);
    return merge(first, RightList);
  }
};