#include <stdio.h>
#include <stdlib.h>

void printNumber(int arr[], int start, int end, int sortType) {
    if(sortType == 1) printf("BubbleSort : ");
    else if(sortType == 2) printf("Partition  : ");
    for (int i = start; i <= end; i++) printf("%d ", arr[i]);
    printf("\n");
}
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int left, int right)
{
    int pivot, low, high;

    low = left;
    high = right + 1;
    pivot = arr[left];
    do {
        do {
            low++;
        } while (low <= right && arr[low] < pivot);
        do {
            high--;
        } while (high >= left && arr[high] > pivot);
        if (low < high) swap(&arr[low], &arr[high]);
    } while (low < high);

    swap(&arr[left], &arr[high]);
    printNumber(arr, left, right,2);
    return high;
}
void bubbleSort(int arr[], int start, int end) {
    for (int i = end; i >= start; i--) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
void quick_sort(int arr[], int left, int right)
{
    if (left < right) {
        if (right - left < 5) {
            bubbleSort(arr, left, right);
            printNumber(arr, left, right, 1);
            return;
        }
        int q = partition(arr, left, right);
        quick_sort(arr, left, q - 1);
        quick_sort(arr, q + 1, right);
    }
}
void qsrt(int arr[]) {
    printf("Quick Sort 정렬 전 \n");
    printNumber(arr, 0, 49, 0);
    printf("\n");
    quick_sort(arr, 0, 49);
    printf("\nQuick Sort 정렬 후 \n");
    printNumber(arr, 0, 49, 0);
}
int main() {
	int arr[50];
	for (int i = 0; i < 50; i++) arr[i] = rand() % 100;	
	qsrt(arr);
}
