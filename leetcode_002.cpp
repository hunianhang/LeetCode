#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(nullptr){}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		ListNode dummyNode(0);
		ListNode* current = &dummyNode;
		int carry = 0;
		while (l1 != nullptr || l2 != nullptr || carry != 0)
		{
			int sum = carry;
			if (l1 != nullptr) 
			{
				sum += l1->val;
				l1 = l1->next;
			}
			if (l2 != nullptr)
			{
				sum += l2->val;
				l2 = l2->next;
			}

			carry = sum / 10;
			current->next = new ListNode(sum % 10);
			current = current->next;
		}
		return dummyNode.next;
	}
};

ListNode* createList(const vector<int>& vals)
{
	ListNode dummy(0);
	ListNode* current = &dummy;
	for (int val : vals)
	{
		current->next = new ListNode(val);
		current = current->next;
	}
	return dummy.next;
}

void printList(ListNode* head)
{
	while (head)
	{
		cout << head->val;
		if (head->next) {
			cout << "->";
		}
		head = head->next;
	}
}

int main()
{
	vector<int> nums1 = { 2,4,3 };
	vector<int> nums2 = { 5,6,4 };
	ListNode* l1 = createList(nums1);
	ListNode* l2 = createList(nums2);

	Solution sol;
	ListNode* result = sol.addTwoNumbers(l1, l2);
	printList(result);
}