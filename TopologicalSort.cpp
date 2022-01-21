// 2017029634_¹Ú¼ºÈ¯_12838
#include <stdio.h>
#include <queue>
#include <stdlib.h> 
#include <string.h> 
#pragma warning (disable:4996)
#pragma warning (disable:6031)
#define WHITE (0) 
#define GRAY (1) 
#define BLACK (2) 

#define TRUE (1) 
#define FALSE (0) 

struct Vertex {
	int color;
	int finishing_time;
	int discovery_time;
};

struct Vertex_info {
	int out_degree;
	int* list;
};

Vertex* vertex;
Vertex_info* vertex_info;
int N, time;
int* topological_list;
int topological_number = 0;
int isDAG = TRUE;

void addEdge(int u, int v)
{
	int i = 0;
	int current = 0;

	for (i = 0; i < N; i++)
	{
		if (vertex_info[u].list[i] == 0)
			break;
		current++;
	}
	vertex_info[u].list[current] = v;
}

void DFS_Visit(int u) {
	int i = 0;
	int v;

	time++;
	vertex[u].color = GRAY;
	vertex[u].discovery_time = time;

	for (i = 0; i < vertex_info[u].out_degree; i++)
	{
		v = vertex_info[u].list[i];
		switch (vertex[v].color)
		{
		case WHITE:
			DFS_Visit(v);
			break;

		case GRAY:
			isDAG = FALSE;
			break;

		case BLACK:
			break;

		default:
			break;
		}
	}

	vertex[u].color = BLACK;
	topological_list[N - (topological_number++)] = u;
	time++;
	vertex[u].finishing_time = time;
}

void sort(int* list, int num)
{
	int i, j;
	int tmp;

	for (i = 0; i < num; i++)
	{
		for (j = i + 1; j < num; j++)
		{
			if (list[i] > list[j])
			{
				tmp = list[i];
				list[i] = list[j];
				list[j] = tmp;
			}
		}
	}
}

void DFS(void)
{
	int i;
	for (i = 1; i <= N; i++)
	{
		vertex[i].discovery_time = 0;
		vertex[i].finishing_time = 0;
		vertex[i].color = WHITE;
		sort(vertex_info[i].list, vertex_info[i].out_degree);
	}

	time = 0;
	for (i = 1; i <= N; i++)
	{
		if (vertex[i].color == WHITE)
			DFS_Visit(i);
	}
}

int main(void) {
	int i, j;
	int u, v;
	int M;

	scanf("%d %d", &N, &M);

	vertex_info = new Vertex_info[N + 1];

	for (i = 1; i <= N; i++)
	{
		vertex_info[i].list = new int[N];
		vertex_info[i].out_degree = 0;
	}

	for (i = 1; i <= N; i++)
		for (j = 0; j < N; j++)
			vertex_info[i].list[j] = 0;

	vertex = new Vertex[N + 1];
	topological_list = new int[N + 1];

	for (i = 0; i < M; i++)
	{
		scanf("%d %d", &u, &v);
		addEdge(u, v);
		vertex_info[u].out_degree++;
	}

	DFS();

	printf("%d\n", isDAG);

	if (isDAG)
	{
		for (i = 1; i <= N; i++)
			printf("%d ", topological_list[i]);
	}

	return 0;
}