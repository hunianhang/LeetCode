#include <stdio.h>
#include <stdlib.h>

int* twoSum_brute_force(int* nums, int numsSize, int target, int* returnSize)
{
	for (int i = 0; i < numsSize - 1; ++i) 
	{
		for (int j = i + 1; j < numsSize; ++j)
		{
			if (nums[i] + nums[j] == target)
			{
				int* result = (int*)malloc(2 * sizeof(int));
				if (result == NULL)
				{
					printf("Memory allocation failed!\n");
					*returnSize = 0;
					return NULL;
				}
				else 
				{
					result[0] = i;
					result[1] = j;
					*returnSize = 2;
					return result;
				}

			}
		}
	}

	*returnSize = 0;
	return NULL;
}
//////////////////////////////////////////

typedef struct {
	int key;
	int value;
}HashItem;


int* twoSum_optimization(int* nums, int numsSize, int target, int* returnSize)
{
	HashItem* hashTable = (HashItem*)malloc(sizeof(HashItem) * numsSize);

	if (hashTable == NULL)
	{
		printf("Allocate the memory failed.\n");
		*returnSize = 0;
		return NULL;
	}

	int hashCount = 0;

	for (int i = 0; i < numsSize; i++)
	{
		int complement = target - nums[i];

		for (int j = 0; j < hashCount; j++)
		{
			if (hashTable[j].key == complement)
			{
				int* result = (int*)malloc(2 * sizeof(int));
				result[0] = hashTable[j].value;
				result[1] = i;

				*returnSize = 2;
				free(hashTable);
				return result;
			}
		}

		hashTable[hashCount].key = nums[i];
		hashTable[hashCount].value = i;
		hashCount++;
	}
	*returnSize = 0;
	free(hashTable);
	return NULL;
}

int main_(void)
{
	int nums[] = { 2,7,11,15 };
	int target = 9;
	int resultSize;

	int* result = twoSum(nums, sizeof(nums), target, &resultSize);

	if (result != NULL)
	{
		printf("Index1 = %d, Index2= %d\n", result[0], result[1]);
		free(result);
	}
	else
	{
		printf("No two sum solution found.\n");
	}

	return 0;
}