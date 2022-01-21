// 2017029634_¹Ú¼ºÈ¯_12838
#include <stdio.h>
#include <string>
#pragma warning (disable:4996)
#pragma warning (disable:6031)

int** graph;
int* visit;

void DFS(int x, int N, int cnt);

int main(void) {
	int N, M;

	scanf("%d %d", &N, &M);

	graph = new int* [N];
	for (int i = 0; i < N; i++)
		graph[i] = new int[N];

	visit = new int[N];
	for (int i = 0; i < N; i++)
		visit[i] = 0;

	int cnt = 0;

	int x, y;

	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &x, &y);
		graph[x - 1][y - 1] = graph[y - 1][x - 1] = 1;
	}

	for (int i = 0; i < N; i++) {
		if (visit[i] == 0) {
			cnt++;
			DFS(i, N, cnt);
		}
	}

	printf("%d\n", cnt);
}

void DFS(int x, int N, int cnt) {
	visit[x] = cnt;
	for (int i = 0; i < N; i++)
	{
		if (graph[x][i] == 1 && visit[i] == 0) {
			DFS(i, N, cnt);
		}
	}
}