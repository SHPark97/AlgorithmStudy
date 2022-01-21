// 2017029634_¹Ú¼ºÈ¯_12838
#include <stdio.h>
#pragma warning (disable:4996)
#pragma warning (disable:6031)

void Max_Heapify(int* Array, int index, int* HeapSize);
void Insert(int* Array, int key, int* HeapSize);
int Extract_Max(int* Array, int* HeapSize);

int main(void) {
	int A, B, C;

	int* ExtractMaxArray = new int[100000];
	int* Array = new int[100000];
	int ExtractMaxIndex = 0;
	int HeapSize = 0;
	int temp, i;

	while (true) {
		A = 0; B = 0; C = 0;

		scanf("%d", &A);

		if (A == 0) {
			for (int i = 0; i < ExtractMaxIndex; i++)
				printf("%d ", ExtractMaxArray[i]);
			printf("\n");
			for (int i = 1; i <= HeapSize; i++)
				printf("%d ", Array[i]);
			break;
		}

		else if (A == 1) {
			scanf("%d", &B);
			Insert(Array, B, &HeapSize);
		}

		else if (A == 2) {
			if (HeapSize > 0)
				ExtractMaxArray[ExtractMaxIndex++] = Extract_Max(Array, &HeapSize);
		}

		else if (A == 3) {
			scanf("%d %d", &B, &C);
			if (HeapSize >= 1) {
				Array[B] = C;
				if (1 < B && Array[B / 2] < Array[B]) {
					while (1 < B && Array[B / 2] < Array[B]) {
						temp = Array[B / 2];
						Array[B / 2] = Array[B];
						Array[B] = temp;
						B = B / 2;
					}
				}
				else Max_Heapify(Array, B, &HeapSize);
			}
		}

	}
}

void Max_Heapify(int* Array, int index, int* HeapSize) {
	int temp;
	int k;

	if (index * 2 > * HeapSize)
		return;

	if (index * 2 == *HeapSize) {
		k = index * 2;
		if (Array[index] < Array[k]) {
			temp = Array[index];
			Array[index] = Array[k];
			Array[k] = temp;
			Max_Heapify(Array, k, HeapSize);
		}
	}
	else {
		if (Array[index * 2 + 1] >= Array[index * 2]) k = index * 2 + 1;
		else k = index * 2;

		if (Array[index] < Array[k]) {
			temp = Array[index];
			Array[index] = Array[k];
			Array[k] = temp;
			Max_Heapify(Array, k, HeapSize);
		}
	}

	return;
}

void Insert(int* Array, int key, int* HeapSize) {
	(*HeapSize)++;
	Array[*HeapSize] = key;
	int i = *HeapSize;
	int temp;

	while (1 < i && Array[i / 2] < Array[i]) {
		temp = Array[i / 2];
		Array[i / 2] = Array[i];
		Array[i] = temp;
		i = i / 2;
	}
}

int Extract_Max(int* Array, int* HeapSize) {
	int Value = Array[1];
	Array[1] = Array[*HeapSize];
	Array[*HeapSize] = Value;
	(*HeapSize)--;

	Max_Heapify(Array, 1, HeapSize);

	return Value;
}