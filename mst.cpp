// 2017029634_박성환_12838
#include <stdio.h>
#pragma warning (disable:4996)
#pragma warning (disable:6031)

struct Edge {
public:
	int u;
	int v;
	int weight;

	Edge (int u_, int v_, int weight_) {
		this->u = u_;
		this->v = v_;
		this->weight = weight_;
	}

	Edge() {
		this->u = 0;
		this->v = 0;
		this->weight = 0;
	}

	bool operator < (Edge& edge) {
		if (this->weight != edge.weight)
			return this->weight < edge.weight;

		else if (this->weight == edge.weight) {
			if (this->u != edge.u)
				return this->u < edge.u;
			else
				return this->v < edge.v;
		}
	}

	bool operator <= (Edge& edge) {
		if (this->weight != edge.weight)
			return this->weight <= edge.weight;

		else if (this->weight == edge.weight) {
			if (this->u != edge.u)
				return this->u <= edge.u;
			else
				return this->v <= edge.v;
		}
	}
};

int getParent(int parent[], int node);
int unionParent(int parent[], int x, int y);
int findParent(int parent[], int x, int y);
void merge(Edge* edge, int left, int mid, int right);
void merge_sort(Edge* edge, int left, int right);

Edge* sorted;

int main() {
	int N, M;

	scanf("%d %d", &N, &M);

	int x, y, w;

	Edge* edges = new Edge[M];
	sorted = new Edge[M];

	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &x, &y, &w);
		edges[i] = Edge(x, y, w);
	}

	merge_sort(edges, 0, M - 1);

	int* parent = new int[N];
	for (int i = 0; i < N; i++)
		parent[i] = i;


	int cnt = 0;
	Edge* arr = new Edge[M];


	for (int i = 0; i < M; i++) {
		if (!findParent(parent, edges[i].u - 1, edges[i].v - 1)) {
			arr[cnt++] = Edge(edges[i].u, edges[i].v, edges[i].weight);
			unionParent(parent, edges[i].u - 1, edges[i].v - 1);
		}
	}


	merge_sort(arr, 0, cnt - 1);


	printf("%d\n", cnt);

	for (int i = 0; i < cnt; i++) {
		printf("%d %d %d\n", arr[i].u, arr[i].v, arr[i].weight);
	}

	return 0;
}


int getParent(int parent[], int node) {
	if (parent[node] == node)
		return node;
	return getParent(parent, parent[node]);
}

int unionParent(int parent[], int x, int y) {
	x = getParent(parent, x);
	y = getParent(parent, y);
	if (x < y) {
		parent[y] = x;
		return x;
	}
	else
	{
		parent[x] = y;
		return y;
	}
}

int findParent(int parent[], int x, int y) {
	x = getParent(parent, x);
	y = getParent(parent, y);
	if (x == y) {
		return 1;
	}
	else
		return 0;
}


void merge(Edge* edge, int left, int mid, int right) {
	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;

	/* 분할 정렬된 edge의 합병 */
	while (i <= mid && j <= right) {
		if (edge[i] <= edge[j])
			sorted[k++] = edge[i++];
		else
			sorted[k++] = edge[j++];
	}

	// 남아 있는 값들을 일괄 복사
	if (i > mid) {
		for (l = j; l <= right; l++)
			sorted[k++] = edge[l];
	}

	// 남아 있는 값들을 일괄 복사
	else {
		for (l = i; l <= mid; l++)
			sorted[k++] = edge[l];
	}

	// 배열 sorted[](임시 배열)의 리스트를 배열 edge[]로 재복사
	for (l = left; l <= right; l++) {
		edge[l] = sorted[l];
	}
}

// 합병 정렬
void merge_sort(Edge* edge, int left, int right) {
	int mid;

	if (left < right) {
		mid = (left + right) / 2;

		merge_sort(edge, left, mid);
		merge_sort(edge, mid + 1, right);

		merge(edge, left, mid, right);
	}
}