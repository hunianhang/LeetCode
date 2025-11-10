class ListNode(object):
    def __init__(self, val= 0, next= None):
        self.val = val
        self.next = next

class Solution:
    def mergeTwoLists(self, l1:ListNode, l2:ListNode)->ListNode:
        dummy = ListNode(0)
        current = dummy

        while l1 and l2:
            if l1.val < l2.val:
                current.next = l1
                l1 = l1.next
            else:
                current.next = l2
                l2 = l2.next

            current = current.next

        current.next = l1 if l1 else l2

        return dummy.next

def list_to_linkedlist(nums):
    dummy = ListNode(0)
    current = dummy
    for n in nums:
        current.next = ListNode(n)
        current = current.next

    return dummy.next

def print_linkedlist(head):
    vals= []
    while head:
        vals.append(head.val)
        head = head.next

    print('->'.join(map(str, vals)))


if __name__ == '__main__':
    list1 = list_to_linkedlist([1, 2, 4])
    list2 = list_to_linkedlist([1, 3, 4])
    solution = Solution()

    merged_list = solution.mergeTwoLists(list1, list2)
    print_linkedlist(merged_list)

