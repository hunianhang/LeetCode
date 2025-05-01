#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(nullptr){}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	stack<int> s1, s2;

	while (l1)
	{
		s1.push(l1->val);
		l1 = l1->next;
	}
	while (l2)
	{
		s2.push(l2->val);
		l2 = l2->next;
	}

	int carry = 0;
	ListNode* result = nullptr;

	while (!s1.empty() || !s2.empty() || carry != 0)
	{
		int sum = carry;

		if (!s1.empty()) {
			sum += s1.top();
			s1.pop();
		}
		if (!s2.empty())
		{
			sum += s2.top();
			s2.pop();
		}

		carry = sum / 10;
		ListNode *newNode = new ListNode(sum % 10);
		newNode->next = result;
		result = newNode;
	}

	return result;
}

ListNode* buildList(const vector<int>& vals) {
	ListNode dummy(0);
	ListNode* cur = &dummy;

	for (int val : vals) {
		cur->next = new ListNode(val);
		cur = cur->next;
	}
	return dummy.next;
}

void printList(ListNode* head)
{
	while (head) {
		cout << head->val;
		if (head->next)
		{
			cout << "->";
		}
		head = head->next;
	}
	cout << endl;
}

int main()
{
	vector<int> num1 = { 7,2,4,3 };
	vector<int> num2 = { 5,6,4 };

	ListNode* l1 = buildList(num1);
	ListNode* l2 = buildList(num2);

	cout << "Input 1:";
	printList(l1);
	cout << "Input 2:";
	printList(l2);

	ListNode* result = addTwoNumbers(l1, l2);

	cout << "result: ";
	printList(result);

	return 0;
}