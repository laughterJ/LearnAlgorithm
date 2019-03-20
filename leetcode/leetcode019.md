```java
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummyHead = new ListNode(0);
        dummyHead.next =head;
        
        ListNode p = dummyHead;
        ListNode q = dummyHead;
        
        while((n--) > 0) p = p.next;
        
        while((p = p.next) != null) q=q.next;
        
        q.next = q.next.next;
     
        return dummyHead.next;
    }
}
```