/**
 * Definition for singly-linked list.
 * class ListNode {
 *     constructor(val = 0, next = null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */

class Solution {
    /**
     * @param {ListNode} head
     * @return {ListNode}
     */
    reverseList(head) {
        if(!head || !head.next) return head;
        const nh = this.reverseList(head.next);
        head.next.next = head;
        head.next = null;
    
        return nh;
    }
}
