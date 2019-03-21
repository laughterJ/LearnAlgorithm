```java

class Solution {
   public ListNode swapPairs(ListNode head) {
       if(head == null) return head;
       ListNode dummyHead = new ListNode(0);
       dummyHead.next = head;
       ListNode p = dummyHead;
       while(head != null && head.next != null){
           p.next = head.next;
           head.next = p.next.next;
           p.next.next = head;
           p = head;
           head = head.next;
       }
       return dummyHead.next;
   }
}
```