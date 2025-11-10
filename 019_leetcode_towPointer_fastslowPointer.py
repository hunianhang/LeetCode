from typing import List


class ListNode:
    def __init__(self, val = 0, next = None):
        self.val = val
        self.next = next

class Solution:
    def removeNthFromEnd(self, head:ListNode, n:int) -> ListNode:
        dummy = ListNode(0)
        dummy.next = head

        first = second = dummy

        for _ in range(n + 1):
            first = first.next

        while first:
            first = first.next
            second = second.next

        second.next = second.next.next

        return dummy.next


def create_linked_list(lst: list[int]) -> ListNode:
    dummy = ListNode(0)
    curr = dummy

    for x in lst:
        curr.next = ListNode(x)
        curr = curr.next

    return dummy.next

def linked_list_to_list(head: ListNode) -> list[int]:
    res = []
    while head:
        res.append(head.val)
        head = head.next

    return res


if __name__ == '__main__':
    head = create_linked_list([1,2,3,4,5])

    s = Solution()
    new_head = s.removeNthFromEnd(head, 2)
    print(linked_list_to_list(new_head))

    head = create_linked_list([1])
    new_head = s.removeNthFromEnd(head, 1)
    print(linked_list_to_list(new_head))