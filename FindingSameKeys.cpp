// 2017029634_¹Ú¼ºÈ¯_12838
#include <stdio.h>
#pragma warning(disable:4996)
#pragma warning(disable:6031)

int main(void) {
	int N, M;

	scanf("%d %d", &N, &M);

	int* A = new int[N];
	int* B = new int[M];

	for (int i = 0; i < N - 1; i++) {
		scanf("%d ", &A[i]);
	}
	scanf("%d", &A[N - 1]);

	for (int i = 0; i < M - 1; i++) {
		scanf("%d ", &B[i]);
	}
	scanf("%d", &B[M - 1]);

	int count = 0;

	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			if (A[j] == B[i])
				count++;

	printf("%d", count);
}