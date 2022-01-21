// 2017029634_¹Ú¼ºÈ¯_12838
#include <stdio.h>
#pragma warning(disable:4996)
#pragma warning(disable:6031)
#define infinity (1<<29)

void print_paren(int** s, int i, int j);

int main(void) {
	int N;
	int* P;

	scanf("%d", &N);

	P = new int[N + 1];

	for (int i = 0; i < N + 1; i++) {
		scanf("%d", &P[i]);
	}

	int** m = new int* [N + 1];
	for (int i = 1; i < N + 1; i++) {
		m[i] = new int[N + 1];
	}

	int** s = new int* [N + 1];
	for (int i = 1; i < N + 1; i++) {
		s[i] = new int[N + 1];
	}

	for (int i = 1; i <= N; i++)
		m[i][i] = 0;

	int j, q;
	for (int l = 2; l <= N; l++) {
		for (int i = 1; i <= N - l + 1; i++) {
			j = i + l - 1;
			m[i][j] = infinity;
			for (int k = i; k <= j - 1; k++) {
				q = m[i][k] + m[k + 1][j] + P[i - 1] * P[k] * P[j];
				if (q < m[i][j]) {
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}

	printf("%d\n", m[1][N]);
	print_paren(s, 1, N);

	delete[] P;
	for (int i = 1; i < N + 1; i++) {
		delete[] m[i];
		delete[] s[i];
	}
	delete[] m;
	delete[] s;

	return 0;
}


void print_paren(int** s, int i, int j) {
	if (i == j) {
		printf("%d", i);
	}
	else {
		printf("(");
		print_paren(s, i, s[i][j]);
		print_paren(s, s[i][j] + 1, j);
		printf(")");
	}
}