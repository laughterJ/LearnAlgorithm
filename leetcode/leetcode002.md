```java
/**
 * Solution 1
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int carry = 0;
        ListNode res = new ListNode(0);
        ListNode sign = res;
        while(l1 != null && l2 != null){
            ListNode cur = new ListNode(0);
            cur.val = (l1.val + l2.val + carry) % 10;
            carry = (l1.val + l2.val + carry) / 10;
            sign.next = cur;
            sign = cur;
            l1 = l1.next;
            l2 = l2.next;
        }
        while(l1 != null){
            ListNode cur = new ListNode(0);
            cur.val = (l1.val + carry) % 10;
            carry = (l1.val + carry) / 10;
            sign.next = cur;
            sign = cur;
            l1 = l1.next;
        }
        while(l2 != null){
            ListNode cur = new ListNode(0);
            cur.val = (l2.val + carry) % 10;
            carry = (l2.val + carry) / 10;
            sign.next = cur;
            sign = cur;
            l2 = l2.next;
        }
        if(carry != 0){
            ListNode cur = new ListNode(carry);
            sign.next = cur;
        }
        return res.next;
    }
}

/**
 * Solution 2 代码优化
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int carry = 0;
        ListNode res = new ListNode(0);
        ListNode sign = res;
        int val1, val2, sum;
        while(l1 != null || l2 != null){
            val1 = l1 != null ? l1.val : 0;
            val2 = l2 != null ? l2.val : 0;
            sum = val1 + val2 + carry;
            ListNode cur = new ListNode(sum % 10);
            carry = sum / 10;
            sign.next = cur;
            sign = cur;
            l1 = l1 == null ? null : l1.next;
            l2 = l2 == null ? null : l2.next;
        }
        if(carry != 0){
            ListNode cur = new ListNode(carry);
            sign.next = cur;
        }
        return res.next;
    }
}

/**
 * Solution 3 代码优化
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int carry = 0;
        ListNode res = new ListNode(0);
        ListNode sign = res;
        while(l1 != null || l2 != null || carry != 0){
            if(l1 != null){
                carry += l1.val;
                l1 = l1.next;
            }
            if(l2 != null){
                carry += l2.val;
                l2 =l2.next;
            }
            sign.next = new ListNode(carry %10);
            carry /= 10;
            sign = sign.next;
        }
        return res.next;
    }
}
```