// 2017029634_¹Ú¼ºÈ¯_12838
#include <stdio.h>
#include <queue>
#include <string>
#pragma warning (disable:4996)
#pragma warning (disable:6031)

using namespace std;

int sum = 0;

struct Node {
	char* str;
	int frequency;
	Node* left;
	Node* right;
};

struct comp {
	bool operator()(Node* left, Node* right) {
		return (left->frequency > right->frequency);
	}
};

Node* getNode(char* str, int frequency, Node* left, Node* right);
void encode(Node* root, string str);
void buildHuffmanTree(char** C, int* P, int N);


int main(void) {
	int N;
	int* P;
	char** C;
	int S;

	scanf("%d", &N);

	P = new int[N];
	C = new char* [N];

	for (int i = 0; i < N; i++) {
		C[i] = new char[4];
	}

	for (int i = 0; i < N; i++) {
		scanf(" %c%c%c%c %d", &C[i][0], &C[i][1], &C[i][2], &C[i][3], &P[i]);
	}

	scanf("%d", &S);

	int k = 1;
	int cnt = 1;
	while (N / k != 1) {
		k = k * 2;
		cnt++;
	}

	printf("%d\n", cnt * S);

	buildHuffmanTree(C, P, N);

	printf("%d\n", sum);

	delete[] P;
	for (int i = 0; i < N; i++)
		delete[] C[i];
	delete[] C;
}


Node* getNode(char* str, int frequency, Node* left, Node* right) {
	Node* new_node = new Node();
	new_node->str = str;
	new_node->frequency = frequency;
	new_node->left = left;
	new_node->right = right;

	return new_node;
}

void encode(Node* root, string str) {
	if (root == NULL)
		return;

	if (!root->left && !root->right) {
		sum += root->frequency * str.length();
	}

	encode(root->left, str + "0");
	encode(root->right, str + "1");
}


void buildHuffmanTree(char** C, int* P, int N) {
	priority_queue<Node*, vector<Node*>, comp> pq;
	
	for (int i = 0; i < N; i++) {
		pq.push(getNode(C[i], P[i], NULL, NULL));
	}


	while (pq.size() != 1) {
		Node* left = pq.top(); pq.pop();
		Node* right = pq.top(); pq.pop();

		pq.push(getNode(NULL, (left->frequency + right->frequency), left, right));
	}

	Node* root = pq.top();

	encode(root, "");
}