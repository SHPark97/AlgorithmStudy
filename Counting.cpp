// 2017029634_¹Ú¼ºÈ¯_12838
#include <stdio.h>

int main() {
	int N, M, K;

	scanf("%d %d %d", &N, &M, &K);

	int* SortedArray = new int[N];
	int* Keys = new int[N];
	int* A = new int[K];
	int* B = new int[K];

	for (int i = 0; i < K; i++)
		scanf("%d %d", &A[i], &B[i]);

	for (int i = 0; i < N; i++)
		scanf("%d", &Keys[i]);

	int* Array = new int[M];

	for (int i = 0; i < M; i++) Array[i] = 0;

	for (int i = 0; i < N; i++) {
		Array[Keys[i] - 1] = Array[Keys[i] - 1] + 1;
	}

	for (int i = 1; i < M; i++) {
		Array[i] = Array[i] + Array[i - 1];
	}

	for (int i = N - 1; i >= 0; i--) {
		SortedArray[Array[Keys[i]]] = Keys[i];
		Array[Keys[i]] = Array[Keys[i]] - 1;
	}

	for (int i = 0; i < K; i++) {
		int count = 0;
		for (int j = 0; j < N; j++)
			if (A[i] <= Keys[j] && Keys[j] <= B[i]) count++;

		printf("%d\n", count);
	}
}