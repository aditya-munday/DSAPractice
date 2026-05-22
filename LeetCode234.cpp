/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
public
  ListNode reverse(ListNode head) {
    ListNode curr = head;
    ListNode fwd = null;
    ListNode prev = null;
    while (curr != null) {
      fwd = curr.next;
      curr.next = prev;
      prev = curr;
      curr = fwd;
    }
    return prev;
  }
public
  boolean isPalindrome(ListNode head) {
    ListNode fast = head;
    ListNode slow = head;
    while (fast.next != null && fast.next.next != null) {
      fast = fast.next.next;
      slow = slow.next;
    }

    ListNode rev = reverse(slow.next);
    while (rev != null) {
      if (rev.val != head.val)
        return false;
      rev = rev.next;
      head = head.next;
    }
    return true;
  }
}