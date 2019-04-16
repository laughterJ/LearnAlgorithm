```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if(head == null || head.next == null || k==0){
            return head;
        }
        // 记录右移k个位置后，head的位置
        ListNode tail = head;
        // 记录链表长度
        int len = 1;
        for(int i=0;i<k;i++){
            if(tail.next != null){
                tail = tail.next;
                len++;
            }else{
            	// k > 链表长度，直接取余，优化遍历时间
                tail = head;
                i=-1;
                k %= len;
            }
        }
        // 若tail回到起点，说明不需要旋转，直接返回head
        if(tail == head){
            return head;
        }
        // 根据head的新位置，确定新的head的位置
        ListNode newStart = head;
        while(tail.next != null){
            tail = tail.next;
            newStart = newStart.next;
        }
        ListNode p = newStart;
        newStart = newStart.next;
        // 将新的 head 的前一个节点的next置为null
        p.next = null;
        // 将末尾节点的next指向原来的head
        tail.next = head;
        return newStart;
    }
}
```