// 2017029634_¹Ú¼ºÈ¯_12838
#include <stdio.h>
#include <queue>
#pragma warning (disable:4996)
#pragma warning (disable:6031)

using namespace std;

typedef pair<int, int> T1;
typedef vector<T1> T2;
typedef vector<T2> T3;

struct AdjList {
    int v;
    int weight;

    AdjList(int v_, int weight_) {
        this->v = v_;
        this->weight = weight_;
    }

    AdjList() {
        this->v = 0;
        this->weight = 0;
    }
};

vector<int> Dijkstra(T3 &adjList, int& start);

int main(void) {
	int N, M;

	scanf("%d %d", &N, &M);

	int x, y, w;

    T3 adjList;

    for (int i = 0; i < N; i++) {
        T2 row;
        adjList.push_back(row);
    }

	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &x, &y, &w);
        adjList[x-1].push_back(make_pair(y-1, w));
	}

    int start_vertex = 0;
    vector<int> dist = Dijkstra(adjList, start_vertex);

    int weight = 0;
    for (int i = 0; i < N; i++) {
        if (weight < dist[i])
            weight = dist[i];
    }

    printf("%d\n", weight);

	return 0;
}

vector<int> Dijkstra(T3& adjList, int& start)
{
    vector<int> dist;

    int n = adjList.size();

    for (int i = 0; i < n; i++)
    {
        dist.push_back(10000000);
    }

    priority_queue<T1, T2, greater<T1> > pq;

    pq.push(make_pair(start, 0));
    dist[start] = 0;

    while (pq.empty() == false)
    {
        int u = pq.top().first;
        pq.pop();

        for (int i = 0; i < adjList[u].size(); i++)
        {
            int v = adjList[u][i].first;
            int weight = adjList[u][i].second;

            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(v, dist[v]));
            }
        }
    }

    return dist;
}