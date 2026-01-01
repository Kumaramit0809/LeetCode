# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # slow = head
        # fast = head
        # while fast and fast.next:
        #     slow = slow.next
        #     fast = fast.next.next
        # return slow

        curr = head
        Length = 0

        while curr != None:
            curr = curr.next
            Length += 1
        curr = head
        for i in range (Length//2):
            curr = curr.next
        
        return curr
