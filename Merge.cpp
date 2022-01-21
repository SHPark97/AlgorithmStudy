// 2017029634_¹Ú¼ºÈ¯_12838
#include <stdio.h>
#pragma warning (disable : 4996)

void MergeSort(int* arr, int p, int r);
void Merge(int* arr, int p, int q, int r);

int main() {
	int num;
	int value;

	scanf("%d", &num);
	int* Array = new int[num];

	for (int i = 0; i < num; i++) {
		scanf("%d", &value);
		Array[i] = value;
	}

	MergeSort(Array, 0, num - 1);

	for (int i = 0; i < num; i++) {
		printf("%d\n", Array[i]);
	}

	delete[] Array;
	return 0;
}

void MergeSort(int* arr, int p, int r) {
	if (p < r) {
		int q = p + (r - p) / 2;
		MergeSort(arr, p, q);
		MergeSort(arr, q + 1, r);
		Merge(arr, p, q, r);
	}
}

void Merge(int* arr, int p, int q, int r) {
	int n1 = q - p + 1; // p~q
	int n2 = r - q;  // q+1~r

	int* L = new int[n1];
	int* R = new int[n2];
	int i, j;

	for (i = 0; i < n1; i++) {
		L[i] = arr[p + i];
	}

	for (j = 0; j < n2; j++) {
		R[j] = arr[q + 1 + j];
	}

	i = 0;
	j = 0;
	int k = p;

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = R[j];
			j++;
		}
		else {
			arr[k] = L[i];
			i++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}

	delete[] L;
	delete[] R;
}