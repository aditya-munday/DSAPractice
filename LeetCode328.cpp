ListNode *temp = head;
ListNode *odd = new ListNode(-1);
ListNode *even = new ListNode(-1);
ListNode *temp1 = odd;
ListNode *temp2 = even;
int count = 1;
while (temp != nullptr) {
  ListNode *next = temp->next;
  if (count % 2 == 0) {
    temp2->next = temp;
    temp2 = temp2->next;
  }

  else {
    temp1->next = temp;
    temp1 = temp1->next;
  }
  temp->next = nullptr;
  temp = next;
  count++;
}

temp = odd->next;
while (temp != nullptr) {
  if (temp->next == nullptr) {
    temp->next = even->next;
    break;
  }
  temp = temp->next;
}
return odd->next;