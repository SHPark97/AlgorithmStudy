// 2017029634_¹Ú¼ºÈ¯_12838
#include <stdio.h>

int main() {
	int num;
	int value;
	int temp;

	scanf("%d", &num);


	int* Array = new int[num];

	for (int i = 0; i < num; i++) {
		scanf("%d", &value);
		Array[i] = value;
	}

	for (int i = 0; i < num - 1; i++) {
		for (int j = i + 1; j > 0; j--) {
			if (Array[j - 1] < Array[j]) {
				temp = Array[j - 1];
				Array[j - 1] = Array[j];
				Array[j] = temp;
			}
			else break;
		}
	}

	for (int i = 0; i < num; i++) {
		printf("%d\n", Array[i]);
	}

	delete[] Array;

	return 0;
}