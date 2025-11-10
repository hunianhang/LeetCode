import heapq

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
        return '->'.join(result)

list1 = ListNode(1,ListNode(4, ListNode(5)))
list2 = ListNode(1,ListNode(3,ListNode(4)))
list3 = ListNode(2,ListNode(6))

lists = [list1,list2,list3]

class Solution(object):
    def mergeKLists(self, lists):
        heap = []

        for i, node in enumerate(lists):
            if node:
                heapq.heappush(heap, (node.val,i, node))

        dummy = ListNode(0)
        current = dummy

        while heap:
            val, i, node = heapq.heappop(heap)

            current.next = node
            current = current.next

            if node.next:
                heapq.heappush(heap, (node.next.val,i, node.next))

        return dummy.next


if __name__ == '__main__':
    s = Solution()
    merged = s.mergeKLists(lists)
    print("Merged List:", merged)
    

