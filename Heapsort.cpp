// 2017029634_¹Ú¼ºÈ¯_12838
#include <stdio.h>

void Max_Heapify(int* Array, int index, int* HeapSize);
void Build_Max_HEAP(int* Array, int* HeapSize);
int Extract_Max(int* Array, int* HeapSize);

int main() {
	int N;
	int K;
	int value;
	int* HeapSize;

	scanf("%d %d", &N, &K);

	int* Array = new int[N];
	HeapSize = &N;

	for (int i = 0; i < N; i++) {
		scanf("%d", &value);
		Array[i] = value;
	}

	Build_Max_HEAP(Array, HeapSize);

	for (int i = 0; i < K; i++)
		printf("%d ", Extract_Max(Array, HeapSize));
	printf("\n");

	for (int i = 0; i < *HeapSize; i++)
		printf("%d ", Array[i]);
	printf("\n");
}

void Max_Heapify(int* Array, int index, int* HeapSize) {
	int temp;
	int k;

	if (index * 2 > * HeapSize)
		return;

	if (index * 2 == *HeapSize) {
		k = index * 2;
		if (Array[index - 1] < Array[k - 1]) {
			temp = Array[index - 1];
			Array[index - 1] = Array[k - 1];
			Array[k - 1] = temp;
			Max_Heapify(Array, k, HeapSize);
		}
	}
	else {
		if (Array[index * 2] > Array[index * 2 - 1]) k = index * 2 + 1;
		else k = index * 2;

		if (Array[index - 1] < Array[k - 1]) {
			temp = Array[index - 1];
			Array[index - 1] = Array[k - 1];
			Array[k - 1] = temp;
			Max_Heapify(Array, k, HeapSize);
		}
	}

	return;
}

void Build_Max_HEAP(int* Array, int* HeapSize) {
	for (int i = *HeapSize / 2; i > 0; i--)
		Max_Heapify(Array, i, HeapSize);
}

int Extract_Max(int* Array, int* HeapSize) {
	int Value = Array[0];
	Array[0] = Array[*HeapSize - 1];
	Array[*HeapSize - 1] = Value;
	(*HeapSize)--;

	Max_Heapify(Array, 1, HeapSize);

	return Value;
}