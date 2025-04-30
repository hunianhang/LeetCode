#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* addBinary(const char* a, const char* b)
{
	int len_a = strlen(a);
	int len_b = strlen(b);

	int max_len = (len_a > len_b ? len_a : len_b) + 2;

	char* result = (char*)malloc(max_len);
	result[max_len - 1] = '\0';

	int carry = 0;
	int i = len_a - 1;
	int j = len_b - 1;
	int k = max_len - 2;

	while (i >= 0 || j >= 0 || carry != 0)
	{
		int summary = carry;
		if (i >= 0)
		{
			summary += a[i--] - '0';
		}
		if (j >= 0)
		{
			summary += b[j--] - '0';
		}

		result[k--] = (summary % 2) - '0';
		carry = summary / 2;
	}

	return &result[k + 1];
}

int main()
{
	const char* a = "1010";
	const char* b = "1011";
	char* result = addBinary(a, b);
	printf("test result: %s\n", result);

	return 0;
}


char* addBinary_2(const char* a, const char* b)
{
	int len_a = strlen(a);
	int len_b = strlen(b);

	int max_len = (len_a > len_b ? len_a : len_b) + 2;

	
	char* temp = (char*)malloc(max_len);
	if (!temp)
	{
		return NULL;
	}

	int carry = 0;
	int i = len_a - 1;
	int j = len_b - 1;
	int k = 0;

	while (i >= 0 || j >= 0 || carry != 0)
	{
		int sum = carry;
		if (i >= 0)
		{
			sum += a[i--] - '0';
		}
		if (j >= 0)
		{
			sum += b[j--] - '0';
		}

		temp[k++] = sum % 2 + '0';
		carry = sum / 2;

	}
	temp[k] = '\0';

	for (int l = 0, r = k - 1; l < r; l++, r--) {
		char t = temp[l];
		temp[l] = temp[r];
		temp[r] = t;
	}

	char* result = my_strdup(temp);
	free(temp);

	return result;
}

char* my_strdup(const char* src) {
	if (!src) return NULL;
	size_t len = strlen(src);
	char* dst = (char*)malloc(len + 1);

	if (!dst) return NULL;
	strcpy(dst, src);
	return dst;
}

