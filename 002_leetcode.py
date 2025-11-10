class ListNode:
    def __init__(self, val=0,next =None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1:ListNode, l2:ListNode) -> ListNode:
        dummy = ListNode(0)
        current = dummy
        carry = 0

        while l1 or l2 or carry:
            val1 = l1.val if l1 else 0
            val2 = l2.val if l2 else 0

            total = val1 + val2 + carry
            carry = total // 10
            current.next = ListNode(total % 10)

            current = current.next
            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next

        return dummy.next


def list_to_linked(nums):
    dummy = ListNode(0)
    cur = dummy
    for num in nums:
        cur.next = ListNode(num)
        cur = cur.next
    return dummy.next

def linked_to_list(node):
    result = []
    while node:
        result.append(node.val)
        node = node.next

    return result

def main():
    print("--- Add Two Numbers ---")
    nums1_str = input("Please input the first number:(using space to seperate them): ")
    nums2_str = input("Please input the second number:(using space to seperate them): ")

    nums1 = list(map(int,nums1_str.split()))
    nums2 = list(map(int,nums2_str.split()))

    l1 = list_to_linked(nums1)
    l2 = list_to_linked(nums2)

    result = Solution().addTwoNumbers(l1,l2)

    print("result:", linked_to_list(result))

if __name__ == '__main__':
    main()