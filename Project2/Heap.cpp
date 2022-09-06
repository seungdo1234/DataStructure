#include <stdio.h>

void insertHeap(int arr[12]) {
	int x, tmp, y;
	printf("서로 다른 정수 11개를 입력하시오. ");
	for (int i = 1; i < 12; i++) {
		y = i;
		scanf("%d", &x);
		arr[i] = x;
		while (i != 1 && arr[i] > arr[i / 2]) {
			tmp = arr[i];
			arr[i] = arr[i / 2];
			arr[i / 2] = tmp;
			i = i / 2;
		}
		i = y;
		for (int j = 1; j <= i; j++) {
			printf("%d   ", arr[j]);
		}
		printf("\n");
	}
}
int deleteHeap(int arr[12], int heap_size) {
	int value, i = 2, x, tmp;
	value = arr[1];
	arr[1] = arr[heap_size];
	arr[heap_size] = value;
	heap_size -= 1;
	while (i <= heap_size) {
		if (i < heap_size && arr[i + 1] > arr[i]) {
			x = i + 1;
		}
		else {
			x = i;
		}
		if (arr[x / 2] > arr[x]) {
			break;
		}
		tmp = arr[x];
		arr[x] = arr[x / 2];
		arr[x / 2] = tmp;
		i = x * 2;
	}
	for (int j = 1; j <= heap_size + 1; j++) {
		printf("%d   ", arr[j]);
	}
	printf("\n");

	return value;
}
int main() {
	int arr[12] = { 0 , };
	int sortArr[12] = { 0, };
	int heap_size = 11;
	insertHeap(arr);
	printf("\n");


	for (int i = 1; i <= 11; i++) {
		sortArr[i] = deleteHeap(arr, heap_size);
		heap_size--;
	}

	printf("\nheap_sort...\n");

	for (int j = 1; j <= 11; j++) {
		printf("%d   ", sortArr[j]);
	}
	printf("\n");

	return 0;
}