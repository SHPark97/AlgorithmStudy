// 2017029634_¹Ú¼ºÈ¯_12838
#include <stdio.h>
#pragma warning(disable:4996)
#pragma warning(disable:6031)

int main(void) {
	int N;
	int e1, e2;
	int x1, x2;
	int* Array1, * Array2;
	int* T1, * T2;

	scanf("%d", &N);

	Array1 = new int[N + 1];
	Array2 = new int[N + 1];
	T1 = new int[N];
	T2 = new int[N];

	scanf("%d %d", &e1, &e2);

	scanf("%d %d", &x1, &x2);

	for (int i = 1; i < N + 1; i++) {
		scanf("%d", &Array1[i]);
	}

	for (int i = 1; i < N + 1; i++) {
		scanf("%d", &Array2[i]);
	}

	for (int i = 1; i < N; i++) {
		scanf("%d", &T1[i]);
	}

	for (int i = 1; i < N; i++) {
		scanf("%d", &T2[i]);
	}

	int** S = new int* [3];
	S[1] = new int[N + 1];
	S[2] = new int[N + 1];
	int** L = new int* [3];
	L[1] = new int[N + 1];
	L[2] = new int[N + 1];

	int s;
	int l;

	S[1][1] = e1 + Array1[1];
	S[2][1] = e2 + Array2[1];

	for (int j = 2; j <= N; j++) {
		if (S[1][j - 1] <= S[2][j - 1] + T2[j - 1]) {
			S[1][j] = S[1][j - 1] + Array1[j];
			L[1][j] = 1;
		}
		else {
			S[1][j] = S[2][j - 1] + T2[j - 1] + Array1[j];
			L[1][j] = 2;
		}

		if (S[2][j - 1] <= S[1][j - 1] + T1[j - 1]) {
			S[2][j] = S[2][j - 1] + Array2[j];
			L[2][j] = 2;
		}
		else {
			S[2][j] = S[1][j - 1] + T1[j - 1] + Array2[j];
			L[2][j] = 1;
		}
	}

	if (S[1][N] + x1 <= S[2][N] + x2) {
		s = S[1][N] + x1;
		l = 1;
	}
	else {
		s = S[2][N] + x2;
		l = 2;
	}

	int* temp = new int[N + 2];

	int i = l;
	temp[N + 1] = i;

	for (int j = N; j > 1; j--) {
		if (i == 1) {
			i = L[1][j];
		}
		else {
			i = L[2][j];
		}
		temp[j] = i;
	}

	printf("%d\n", s);

	for (int i = 1; i <= N; i++) {
		printf("%d %d\n", temp[i + 1], i);
	}

	delete[] Array1;
	delete[] Array2;
	delete[] T1;
	delete[] T2;
	delete[] S[0];
	delete[] S[1];
	delete[] S[2];
	delete[] L[0];
	delete[] L[1];
	delete[] L[2];
}