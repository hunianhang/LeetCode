class ListNode(object):
    def __init__(self, val = 0, next = None):
        self.val = val
        self.next = next

    def __str__(self):
        result = []
        node = self
        while node:
            result.append(str(node.val))
            node = node.next

        return "->".join(result)


class Solution(object):
    def swapPairs(self, head):
        dummy = ListNode(0)
        dummy.next = head
        current = dummy

        while current.next and current.next.next:
            first = current.next
            second = current.next.next

            first.next = second.next
            second.next = first
            current.next = second

            current = first
        return dummy.next


if __name__ == '__main__':
    s = Solution()
    print(s.swapPairs(ListNode(1, ListNode(2, ListNode(3,ListNode(4))))))