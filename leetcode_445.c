#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int val;
	struct ListNode* next;
}ListNode;

ListNode* createNode(int val) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->val = val;
	node->next = NULL;
	return node;
}

void pushToStack(ListNode* head, int* stack, int* top) {
	while (head) {
		stack[(*top)++] = head->val;
		head = head->next;
	}
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	int stack1[100];
	int stack2[100];

	int top1 = 0;
	int top2 = 0;
	
	pushToStack(l1, stack1, &top1);
	pushToStack(l2, stack2, &top2);

	int carry = 0;
	ListNode* result = NULL;

	while (top1 > 0 || top2 > 0 || carry != 0)
	{
		int val1 = (top1 > 0) ? stack1[--top1] : 0;
		int val2 = (top2 > 0) ? stack2[--top2] : 0;

		int sum = val1 + val2 + carry;
		carry = sum / 10;
		ListNode* node = createNode(sum % 10);

		node->next = result;
		result = node;
	}

	return result;
}

void printList(ListNode* head)
{
	while (head)
	{
		printf("%d", head->val);
		if (head->next)
		{
			printf("->");
		}
		head = head->next;
	}
	printf("\n");
}

ListNode* buildList(int* arr, int size) {
	if (size == 0)
		return NULL;

	ListNode* head = createNode(arr[0]);
	ListNode* current = head;

	for (int i = 1;i < size; ++i)
	{
		current->next = createNode(arr[i]);
		current = current->next;
	}
	return head;
}

int main()
{
	int arr1[] = { 7,2,4,3 };
	int arr2[] = { 5,6,4 };

	ListNode* l1 = buildList(arr1, sizeof(arr1) / sizeof(int));
	ListNode* l2 = buildList(arr2, sizeof(arr2) / sizeof(int));

	printf("Input 1: ");
	printList(l1);
	printf("Input 2: ");
	printList(l2);

	ListNode* result = addTwoNumbers(l1, l2);

	printf("Result: ");
	printList(result);

	return 0;
}