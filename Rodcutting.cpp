// 2017029634_¹Ú¼ºÈ¯_12838
#include <stdio.h>
#pragma warning(disable:4996)
#pragma warning(disable:6031)
#define infinity (1<<29)

int main(void) {
	int N;
	int* P;

	scanf("%d", &N);

	P = new int[N + 1];
	for (int i = 1; i < N + 1; i++)
		scanf("%d", &P[i]);


	int* r = new int[N + 1];
	int* s = new int[N + 1];
	r[0] = 0;

	int q;
	for (int j = 1; j <= N; j++) {
		q = -1 * infinity;
		for (int i = 1; i <= j; i++) {
			if (q < P[i] + r[j - i]) {
				q = P[i] + r[j - i];
				s[j] = i;
			}
		}
		r[j] = q;
	}

	printf("%d\n", r[N]);

	while (N > 0) {
		printf("%d\n", s[N]);
		N = N - s[N];
	}

	delete[] P;
	delete[] r;
	delete[] s;
}